#include <bits/stdc++.h>
using namespace std;

using point_t=long long;  //全局数据类型，可修改为 long long 等

constexpr point_t eps=0;
constexpr long double PI=3.1415926535897932384l;

// 点与向量
template<typename T> struct point
{
    T x,y;
    // int id=-1;
    bool operator==(const point &a) const {return (abs(x-a.x)<=eps && abs(y-a.y)<=eps);}
    bool operator<(const point &a) const {if (abs(x-a.x)<=eps) return y<a.y-eps; return x<a.x-eps;}
    bool operator>(const point &a) const {return !(*this<a || *this==a);}
    point operator+(const point &a) const {return {x+a.x,y+a.y};}
    point operator-(const point &a) const {return {x-a.x,y-a.y};}
    point operator-() const {return {-x,-y};}
    point operator*(const T k) const {return {k*x,k*y};}
    point operator/(const T k) const {return {x/k,y/k};}
    T operator*(const point &a) const {return x*a.x+y*a.y;}  // 点积
    T operator^(const point &a) const {return x*a.y-y*a.x;}  // 叉积，注意优先级
    int toleft(const point &a) const {const auto t=(*this)^a; return (t>eps)-(t<-eps);}  // to-left 测试
    T len2() const {return (*this)*(*this);}  // 向量长度的平方
    T dis2(const point &a) const {return (a-(*this)).len2();}  // 两点距离的平方

    // 涉及浮点数
    long double len() const {return sqrtl(len2());}  // 向量长度
    long double dis(const point &a) const {return sqrtl(dis2(a));}  // 两点距离
    long double ang(const point &a) const {return acosl(max(-1.0l,min(1.0l,((*this)*a)/(len()*a.len()))));}  // 向量夹角
    point rot(const long double rad) const {return {x*cos(rad)-y*sin(rad),x*sin(rad)+y*cos(rad)};}  // 逆时针旋转（给定角度）
    point rot(const long double cosr,const long double sinr) const {return {x*cosr-y*sinr,x*sinr+y*cosr};}  // 逆时针旋转（给定角度的正弦与余弦）
};

using Point=point<point_t>;

// 极角排序
struct argcmp
{
    bool operator()(const Point &a,const Point &b) const
    {
        const auto quad=[](const Point &a)
        {
            if (a.y<-eps) return 1;
            if (a.y>eps) return 4;
            if (a.x<-eps) return 5;
            if (a.x>eps) return 3;
            return 2;
        };
        const int qa=quad(a),qb=quad(b);
        if (qa!=qb) return qa<qb;
        const auto t=a^b;
        // if (abs(t)<=eps) return a*a<b*b-eps;  // 不同长度的向量需要分开
        return t>eps;
    }
};

// 直线
template<typename T> struct line
{
    point<T> p,v;  // p 为直线上一点，v 为方向向量

    bool operator==(const line &a) const {return v.toleft(a.v)==0 && v.toleft(p-a.p)==0;}
    int toleft(const point<T> &a) const {return v.toleft(a-p);}  // to-left 测试
    bool operator<(const line &a) const  // 半平面交算法定义的排序
    {
        if (abs(v^a.v)<=eps && v*a.v>=-eps) return toleft(a.p)==-1;
        return argcmp()(v,a.v);
    }

    // 涉及浮点数
    point<T> inter(const line &a) const {return p+v*((a.v^(p-a.p))/(v^a.v));}  // 直线交点
    long double dis(const point<T> &a) const {return abs(v^(a-p))/v.len();}  // 点到直线距离
    point<T> proj(const point<T> &a) const {return p+v*((v*(a-p))/(v*v));}  // 点在直线上的投影
};

using Line=line<point_t>;

//线段
template<typename T> struct segment
{
    point<T> a,b;

    bool operator<(const segment &s) const {return make_pair(a,b)<make_pair(s.a,s.b);}

    // 判定性函数建议在整数域使用

    // 判断点是否在线段上
    // -1 点在线段端点 | 0 点不在线段上 | 1 点严格在线段上
    int is_on(const point<T> &p) const  
    {
        if (p==a || p==b) return -1;
        return (p-a).toleft(p-b)==0 && (p-a)*(p-b)<-eps;
    }

    // 判断线段直线是否相交
    // -1 直线经过线段端点 | 0 线段和直线不相交 | 1 线段和直线严格相交
    int is_inter(const line<T> &l) const
    {
        if (l.toleft(a)==0 || l.toleft(b)==0) return -1;
        return l.toleft(a)!=l.toleft(b);
    }
    
    // 判断两线段是否相交
    // -1 在某一线段端点处相交 | 0 两线段不相交 | 1 两线段严格相交
    int is_inter(const segment<T> &s) const
    {
        if (is_on(s.a) || is_on(s.b) || s.is_on(a) || s.is_on(b)) return -1;
        const line<T> l{a,b-a},ls{s.a,s.b-s.a};
        return l.toleft(s.a)*l.toleft(s.b)==-1 && ls.toleft(a)*ls.toleft(b)==-1;
    }

    // 点到线段距离
    long double dis(const point<T> &p) const
    {
        if ((p-a)*(b-a)<-eps || (p-b)*(a-b)<-eps) return min(p.dis(a),p.dis(b));
        const line<T> l{a,b-a};
        return l.dis(p);
    }

    // 两线段间距离
    long double dis(const segment<T> &s) const
    {
        if (is_inter(s)) return 0;
        return min({dis(s.a),dis(s.b),s.dis(a),s.dis(b)});
    }
};

using Segment=segment<point_t>;
bool check(vector<Segment> &vec)
{
    for(int i=0;i<3;++i)
    for(int j=i+1;j<3;++j)
    if(vec[i].is_inter(vec[j])==0)return 1;
    
    for(int i=0;i<3;++i)
    for(int j=0;j<3;++j)
    if(i!=j)
    if((vec[i].a.y-vec[i].b.y)*(vec[j].a.x-vec[j].b.x)
    ==(vec[j].a.y-vec[j].b.y)*(vec[i].a.x-vec[i].b.x))
    return 1;
    
        if((vec[1].is_on(vec[0].a))
        &&vec[2].is_on(vec[0].b))
        {
            swap(vec[0],vec[2]);
            return 0;
        }
        
        if((vec[1].is_on(vec[0].b))
        &&vec[2].is_on(vec[0].a))
        {
            swap(vec[0],vec[2]);
            
            return 0;
        }
        
        if((vec[0].is_on(vec[1].a))
        &&vec[2].is_on(vec[1].b))
        {
        swap(vec[1],vec[2]);
        return 0;
        }
        
        if((vec[0].is_on(vec[1].b))
        &&vec[2].is_on(vec[1].a))
        {
        swap(vec[1],vec[2]);
        return 0;
        }
        
        if((vec[1].is_on(vec[2].a))
        &&vec[0].is_on(vec[2].b))
        return 0;
        
        if((vec[1].is_on(vec[2].b))
        &&vec[0].is_on(vec[2].a))return 0;
    
    return 1;
}
vector<Point> dot;
void print(Segment a)
{
    cout<<"Seg-->"<<a.a.x<<" "<<a.a.y<<" "<<a.b.x<<" "<<a.b.y<<endl;
}
bool check_vec(vector<Line> vec)
{
    if(vec[0].v.toleft(vec[1].v)==0)return true;
    if(vec[0].v.toleft(vec[2].v)==0)return true;
    if(vec[1].v.toleft(vec[2].v)==0)return true;
    return false;
}
bool check2(vector<Segment> vec)
{
    if(vec[0].a==vec[1].a)
    {
        dot.push_back(vec[0].a);dot.push_back(vec[0].b);
        dot.push_back(vec[1].a);dot.push_back(vec[1].b);
        return 0;
    }
    if(vec[0].b==vec[1].b)
    {
        dot.push_back(vec[0].b);dot.push_back(vec[0].a);
        dot.push_back(vec[1].b);dot.push_back(vec[1].a);
        return 0;
    }
    
    if(vec[1].b==vec[0].a)
    {dot.push_back(vec[1].b);dot.push_back(vec[1].a);
    dot.push_back(vec[0].a);dot.push_back(vec[0].b);
    return 0;}
    
    if(vec[0].b==vec[1].a)
    {dot.push_back(vec[1].a);dot.push_back(vec[1].b);
    dot.push_back(vec[0].b);dot.push_back(vec[0].a);
    return 0;}
    
    return 1;
}
bool ccheck(vector<Point> vec)
{
    Segment s1={vec[0],vec[1]};
    if(s1.is_on(vec[4])==0)swap(vec[4],vec[5]);
    point_t l1=vec[0].dis2(vec[4]),l2=vec[2].dis2(vec[5]),
    
    l3=vec[1].dis2(vec[4]),l4=vec[0].dis2(vec[4]),
    l6=vec[2].dis2(vec[5]),l7=vec[3].dis2(vec[5]),
    l5=vec[4].dis2(vec[5]);
    if(l1+l2-l5<0)return false;
    if(max(l4,l3)>(__int128)min(l4,l3)*16)return false;
    if(max(l6,l7)>(__int128)min(l6,l7)*16)return false;
    return true;
}
bool is_right_triangle(vector<Point> &vec)
{
    point_t a=vec[0].dis2(vec[1]),b=vec[2].dis2(vec[3]),
    c=vec[4].dis2(vec[5]);
    if(a+b==c||a+c==b||b+c==a)return true;
    return false;
}
void solve()
{
    dot.clear();
    vector<Point> vec(6);
    for(point_t i=0,x,y;i<6;++i)
    {
        scanf("%lld%lld",&x,&y);
        vec[i]={x,y};
    }
        vector<Line>vecl(3);
    vector<Segment>vecs(3);
    for(int i=0;i<3;++i)
    vecs[i]={vec[i*2],vec[(i*2)^1]};
    // for(int i=0;i<3;++i)
    if(check(vecs)){printf("NO\n");return ;}
    if(check2(vecs)){printf("NO\n");return ;}
       if(is_right_triangle(vec)) {printf("NO\n");return ;}
        dot.push_back(vecs[2].a);
            dot.push_back(vecs[2].b);

    for(int i=0;i<3;++i)
    vec[i*2]=vecs[i].a,vec[(i*2)^1]=vecs[i].b;
    
        for(int i=0;i<3;++i)
    {
        vecl[i]={vec[i*2],vec[(i*2)^1]-vec[i*2]};
    }
    // if(check_vec(vecl)){printf("NO\n");return ;}


    if(ccheck(dot)) {printf("YES\n");return ;}

    printf("NO\n");
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)solve();
}