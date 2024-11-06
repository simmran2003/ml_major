#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int INF=0x3f3f3f3f,maxn=505;
struct Point
{
    int x,y;
    Point(){};
    Point(int _x,int _y)
    {
        x=_x,y=_y;
    }
    Point operator-(const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    ll operator*(const Point &b)const
    {
        return (ll)x*b.y-(ll)y*b.x;
    }
}a[maxn],b[maxn];
int n,m,dp[maxn][maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
    for(int i=1;i<=m;i++)scanf("%d%d",&b[i].x,&b[i].y);
    a[0]=Point(-1e9-1,-1e9-1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if((a[i]-a[0])*(a[j]-a[0])<=0)continue;
            for(int k=1;k<=m;k++)
                if((a[i]-a[0])*(b[k]-a[0])>=0&&(a[j]-a[i])*(b[k]-a[i])>=0&&(b[k]-a[0])*(a[j]-a[0])>=0)
                    dp[i][j]++;
            dp[j][i]=-dp[i][j];
        }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                if(dp[i][j]+dp[k][i]+dp[j][k]==0)
                    ans++;
    printf("%d\n",ans);
    return 0;
}