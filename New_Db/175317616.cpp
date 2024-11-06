#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
static const int MAXN=500+10;
int cnt[MAXN][MAXN];
struct Point{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
    void input() { scanf("%d%d",&x,&y); }
    bool operator<(const Point &b)const{ return y<b.y; }
    ll operator^(const Point &b)const{ return 1ll*x*b.y-1ll*y*b.x; }
}red[MAXN],blue[MAXN];
bool check(Point a,Point b,Point c) { return c.y>=a.y && c.y<b.y && (a^b)+(b^c)+(c^a)>0; }
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) red[i].input();
    for(int i=1;i<=m;i++) blue[i].input();
    sort(red+1,red+n+1);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=1;k<=m;k++)
                if(check(red[i],red[j],blue[k])) cnt[i][j]++;
    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                if(cnt[i][j]+cnt[j][k]==cnt[i][k]) res++;
    printf("%d\n",res);
    return 0;
}
