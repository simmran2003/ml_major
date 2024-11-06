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
const double eps=1e-9;
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i].x>>b[i].y;
    }
    a[0]=Point(-1e9-1,-1e9-1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((a[i]-a[0])*(a[j]-a[0])<=0) continue;
            for(int k=1;k<=m;k++)
            {
                int now=((b[k]-a[0])*(b[k]-a[i])>0)+((b[k]-a[i])*(b[k]-a[j])>0)+((b[k]-a[j])*(b[k]-a[0])>0);
                if(now==0 || now>=3) dp[i][j]++;
            }
            dp[j][i]=-dp[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(dp[i][j]+dp[j][k]+dp[k][i]==0)
                {
                    // cout<<i<<" "<<j<<" "<<k<<endl;
                    ans++;
                }
            }
        }
    }    
    cout<<ans<<endl;
    return 0;
}