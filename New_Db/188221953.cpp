#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long long
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef  Point Vector;
Vector operator - (Point A, Point B){return Vector(A.x - B.x, A.y - B.y);}
Vector operator * (Vector A, double p){return Vector(A.x * p, A.y * p);}
Vector operator + (Vector A, Vector B){return Vector(A.x + B.x, A.y + B.y);}
struct Line{
    Vector v;
    Point p;
    Line(){};
    Line(Vector v,Point p):v(v),p(p){}
    Point get_point_in_line(double t)
    {
        return v+(p-v)*t;
    }
};
/* double eps=1e-30;
int sgn(double x)
{
    if(fabs(x)<eps)
    {
        return 0;
    }
    if(x<0)
        return -1;
    return 1;
} */
const double pi=acos(-1);
double Dot(Vector A, Vector B){return A.x * B.x + A.y * B.y;}
inline double R_to_D(double rad)// 弧度转角度
{ return 180/pi*rad; }

double Length(Vector A){return sqrt(Dot(A, A));}
double Angle(Vector A, Vector B){return acos(fabs((Dot(A, B) / Length(A) / Length(B))));}

double Cross(Vector A, Vector B){return A.x *  B.y - B.x * A.y;}
bool OnSegment(Point p, Point a1, Point a2){
/*     cout<<"judge "<<endl;
    cout<<p.x<<" "<<p.y<<endl;
    cout<<a1.x<<" "<<a1.y<<endl;
    cout<<a2.x<<" "<<a2.y<<endl;
    cout<<Cross(a1-p, a2-p)<<" "<<Dot(a1-p,a2-p)<<endl; */
    return (Cross(a1-p, a2-p) ==0)&&(Dot(a1-p,a2-p)<0);
}
double dis(Point p1,Point p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
bool judge(Point p,Line L)
{
    if(OnSegment(p,L.p,L.v+L.p))
    {
 /*        cout<<p.x<<" "<<p.y<<"-----"<<L.p.x<<" "<<L.p.y<<"---"<<(L.v+L.p).x<<" "<<(L.v+L.p).y<<endl; */
        double xx1=dis(p,L.p);
        double xx2=dis(p,(L.v+L.p));
        if(xx1-xx2>0) swap(xx1,xx2);
/*         cout<<"-----"<<xx1<<" "<<xx2<<endl; */
        if(16*xx1-xx2>=0)
        {
            
            return 1;
        }else
        {
            return 0;
        }
    }else
    {
/*         cout<<"pp"<<endl; */
        return 0;
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n=3;
        map<pair<int,int>,vector<int>>mp;
        Line l[4];
        set<pair<int,int>>se;
        for(int i=1;i<=n;i++)
        {
            int a1,b1,a2,b2;
            cin>>a1>>b1>>a2>>b2;
            l[i]=Line({a2-a1,b2-b1},{a1,b1});
            mp[{a1,b1}].push_back(i);
            mp[{a2,b2}].push_back(i);
            se.insert({a1,b1});
            se.insert({a2,b2});
        }   
        Point aa;
        Line new_l[4];
        int cnt=0;
        if(se.size()!=5)
        {
            cout<<"NO"<<endl;
            continue;
        }else
        {
            for(auto it:se)
            {
                if(mp[it].size()==2)
                {
                    aa.x=it.first,aa.y=it.second;
                    new_l[1]=l[mp[it][0]];
                    new_l[2]=l[mp[it][1]];
/*                     if(mp[it][0]==mp[it][1])
                    {
                        cout<<"NO"<<endl;
                        return 0;
                    } */
                    new_l[3]=l[6-mp[it][0]-mp[it][1]];
                    break;
                }
            }
        }
        Point bb,cc;
        if(new_l[1].p.x==aa.x&&new_l[1].p.y==aa.y)
        {
            bb={(new_l[1].p+new_l[1].v).x,(new_l[1].p+new_l[1].v).y};
        }else
        {
            bb={(new_l[1].p).x,(new_l[1].p).y};
        }

        if(new_l[2].p.x==aa.x&&new_l[2].p.y==aa.y)
        {
            cc={(new_l[2].p+new_l[2].v).x,(new_l[2].p+new_l[2].v).y};
        }else
        {
            cc={(new_l[2].p).x,(new_l[2].p).y};
        }     

        if(dis(aa,bb)+dis(aa,cc)<dis(bb,cc))   
        {
            cout<<"NO"<<endl;
            continue;
        }
/*         for(int i=1;i<=3;i++)
        {
            cout<<new_l[i].p.x<<" "<<new_l[i].p.y<<endl;
        }
        cout<<new_l[1].v.x<<" "<<new_l[1].v.y<<endl;
        cout<<new_l[2].v.x<<" "<<new_l[2].v.y<<endl; */

/*         double alpha=Angle(new_l[1].v,new_l[2].v); */

        if((judge(new_l[3].p,new_l[1])&&judge(new_l[3].p+new_l[3].v,new_l[2]))||(judge(new_l[3].p,new_l[2])&&judge(new_l[3].p+new_l[3].v,new_l[1])))
        {
            cout<<"YES"<<endl;
        }else
        {
            cout<<"NO"<<endl;
        }



        


    }
}