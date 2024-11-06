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
bool check_top(vector<Point> &vec)
{
    if(vec[0]==vec[1]||vec[2]==vec[3]||vec[4]==vec[5]){return 1;}
    
    if(vec[0]==vec[2])return 0;
    if(vec[0]==vec[3]){swap(vec[3],vec[2]);return 0;}
    if(vec[0]==vec[4]){swap(vec[2],vec[4]);swap(vec[3],vec[5]);return 0;}
    if(vec[0]==vec[5])
    {swap(vec[2],vec[5]);swap(vec[3],vec[4]);return 0;}
    
    if(vec[1]==vec[2])
    {swap(vec[0],vec[1]);return 0;}
    if(vec[1]==vec[3])
    {swap(vec[0],vec[1]);swap(vec[2],vec[3]);return 0;}
    if(vec[1]==vec[4])
    {swap(vec[0],vec[1]);swap(vec[2],vec[4]);swap(vec[3],vec[5]);return 0;}
    if(vec[1]==vec[5])
    {swap(vec[1],vec[0]);swap(vec[2],vec[5]);swap(vec[3],vec[4]);return 0;}
    
    if(vec[2]==vec[4])
    {swap(vec[0],vec[4]);swap(vec[1],vec[5]);return 0;}
    if(vec[2]==vec[5])
    {swap(vec[0],vec[5]);swap(vec[1],vec[4]);return 0;}
    
    if(vec[3]==vec[4])
    {swap(vec[2],vec[3]);swap(vec[0],vec[4]);swap(vec[1],vec[5]);return 0;}
    if(vec[3]==vec[5])
    {swap(vec[2],vec[3]);swap(vec[0],vec[5]);swap(vec[1],vec[4]);return 0;}
    
    return 1;
}
bool check_bottom(vector<Point> &vec)
{
    Segment s1={vec[0],vec[1]},s2={vec[2],vec[3]};
    if(s1.is_on(vec[4])&&s2.is_on(vec[5]))return 0;
    if(s1.is_on(vec[5])&&s2.is_on(vec[4]))
    {swap(vec[4],vec[5]);return 0;}
    return 1;
}
bool check(vector<Point> vec)
{
    point_t 
    l1=vec[0].dis2(vec[4]),l2=vec[2].dis2(vec[5]),
    l3=vec[4].dis2(vec[5]),
    l4=vec[1].dis2(vec[4]),l5=vec[3].dis2(vec[5]);
    if(l1+l2-l3<0)return 1;
    if(max(l1,l4)>min(l1,l4)*16)return 1;
    if(max(l2,l5)>min(l2,l5)*16)return 1;
    return 0;
}
void solve()
{
    vector<Point> vec(6);
    for(auto &[x,y]:vec)scanf("%lld%lld",&x,&y);
    if(check_top(vec)){printf("NO\n");return ;}
    if(check_bottom(vec)){printf("NO\n");return ;}
    if(check(vec)){printf("NO\n");return ;}
    printf("YES\n");
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)solve();
}