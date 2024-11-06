#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
struct point{
    int x,y;
}p[501],p2[501];
inline point operator-(point a, point b){
    return {a.x-b.x,a.y-b.y};
}
inline int operator*(point a, point b){
    return a.x*b.y-a.y*b.x;
}
int f(point a, point b, point c){
    return abs(a*b+b*c+c*a);
}
int n,m,dp[501][501],mn,res;
signed main(){
    ios_base::sync_with_stdio(NULL);cin.tie(nullptr);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> p[i].x >> p[i].y;
        mn=min(mn,p[i].y);
    }
    sort(p+1,p+n+1,[](point a, point b){
            return (a.x==b.x?(a.y<b.y):(a.x<b.x));
        });
    for (int i=1;i<=m;i++){
        cin >> p2[i].x >> p2[i].y;
        mn=min(mn,p2[i].y);
    }
    for (int i=1;i<=n;i++)
        p[i]={p[i].x,p[i].y-mn};
    for (int i=1;i<=m;i++)
        p2[i]={p2[i].x,p2[i].y-mn};
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++){
            int area=(p[i].y+p[j].y)*abs(p[i].x-p[j].x);
            point a=p[i],b={p[i].x,0},c={p[j].x,0},d=p[j];
            for (int k=1;k<=m;k++)
                dp[i][j]+=(p2[k].x!=p[i].x&&f(p2[k],a,b)+f(p2[k],b,c)+f(p2[k],c,d)+f(p2[k],d,a)==area);
        }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            for (int k=j+1;k<=n;k++)
                if (abs(dp[i][j]+dp[j][k]-dp[i][k])==0)
                    res++;
    cout << res;
}
