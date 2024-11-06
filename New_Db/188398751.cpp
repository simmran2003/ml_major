#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
typedef double db;
static const db EPS=1e-8;
int sgn(db x)
{
    if(fabs(x)<EPS) return 0;
    if(x<0) return -1;
    return 1;
}
struct Point{
    double x,y;
    Point(){}
    Point(db _x,db _y):x(_x),y(_y){}
    Point operator-(const Point &b)const{ return Point(x-b.x,y-b.y); }
    db operator*(const Point &b)const{ return x*b.x+y*b.y; }
    db operator^(const Point &b)const{ return x*b.y-y*b.x; }
    bool operator==(const Point &b)const{ return sgn(x-b.x)==0 && sgn(y-b.y)==0; }
    void input() { scanf("%lf%lf",&x,&y); }
    db len2() { return x*x+y*y; }
};
struct Line{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e):s(_s),e(_e){}
    void input() { s.input(); e.input(); }
}line[3];
int T;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<3;i++) line[i].input();
        int r[3]={-1,-1,-1};
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(i!=j && (line[i].s==line[j].s || line[i].s==line[j].e || line[i].e==line[j].e))
                    r[0]=i,r[1]=j,r[2]=3^i^j;
        if(r[0]<0) { puts("NO"); continue; }
        if(line[r[0]].s==line[r[1]].e) swap(line[r[1]].s,line[r[1]].e);
        if(sgn((line[r[0]].s-line[r[0]].e)^(line[r[1]].s-line[r[1]].e))==0
        || sgn((line[r[0]].s-line[r[0]].e)*(line[r[1]].s-line[r[1]].e))<0)
        {
            puts("NO");
            continue;
        }
        bool flag=false;
        for(int i=0;i<2;i++)
        {
            if(sgn((line[r[2]].s-line[r[0]].s)^(line[r[2]].s-line[r[0]].e))==0
            && 5*((line[r[2]].s-line[r[0]].s)*(line[r[0]].e-line[r[0]].s))>=(line[r[0]].s-line[r[0]].e).len2()
            && 5*((line[r[2]].s-line[r[0]].s)*(line[r[0]].e-line[r[0]].s))<=4*(line[r[0]].s-line[r[0]].e).len2()
            && sgn((line[r[2]].e-line[r[1]].s)^(line[r[2]].e-line[r[1]].e))==0
            && 5*((line[r[2]].e-line[r[1]].s)*(line[r[1]].e-line[r[1]].s))>=(line[r[1]].s-line[r[1]].e).len2()
            && 5*((line[r[2]].e-line[r[1]].s)*(line[r[1]].e-line[r[1]].s))<=4*(line[r[1]].s-line[r[1]].e).len2()
            ) flag=true;
            swap(r[0],r[1]);
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}

 	  		  	 		  		    	  				