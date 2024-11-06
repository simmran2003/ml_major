#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll maxN=2e5;
#define taskname "codeforce"
#define int long long
struct pt
{
    ll a,b;
    bool operator<(const pt&o)
    {
        return a<o.a;
    }
}x[maxN],d[maxN];
struct Tvector
{
    ll u,v;
    Tvector(pt a, pt b)
    {
        u=a.a-b.a;
        v=a.b-b.b;
    }
};
ll mul(Tvector a, Tvector b)
{
    return abs(a.u*b.v-b.u*a.v);
}
ll s(pt a,pt b,pt c,pt d)
{
    Tvector x1(a,b);
    Tvector x2(a,c);
    Tvector x3(a,d);
    return mul(x1,x2)+mul(x2,x3);
}
bool check(pt x,pt a,pt b,pt c,pt d)
{
    Tvector x1(x,a);
    Tvector x2(x,b);
    Tvector x3(x,c);
    Tvector x4(x,d);
    if(mul(x1,x2)+mul(x2,x3)+mul(x3,x4)+mul(x4,x1)==s(a,b,c,d)) return true;
    return false;
}
ll dp[501][501],n,m;
bool c(ll i,ll j,ll k)
{
    return dp[i][j]+dp[j][k]==dp[i][k];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ///freopen(taskname".inp","r",stdin);
    ///freopen(taskname".out","w",stdout);
    srand(time(0));
    cin >> n >> m;
    ll del=0;
    for(int i=1;i<=n;i++) cin >> x[i].a >> x[i].b,del=min(del,x[i].b);
    for(int i=1;i<=m;i++) cin >> d[i].a >> d[i].b;
    sort(x+1,x+n+1);
    del=abs(del);
    //cout << '\n';
    for(int i=1;i<=n;i++) x[i].b+=del;//,cout <<x[i].a<<' '<<x[i].b<<'\n';;
    for(int i=1;i<=m;i++) d[i].b+=del;//cout <<d[i].a<<' '<<d[i].b<<'\n';;
    for(int i=1;i<=n;i++)
    {
        dp[i][i]=0;
        for(int j=i+1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                if(d[k].b<0) continue;
                if(d[k].a==x[i].a&&check(d[k],x[i],x[j],(pt){x[j].a,0},(pt){x[i].a,0})==1) continue;
                dp[i][j]+=check(d[k],x[i],x[j],(pt){x[j].a,0},(pt){x[i].a,0});
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(c(i,j,k)) ans++;
            }
        }
    }
    cout << ans;
}
