#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define el "\n"
#define pt complex<ld>
#define vec(a,b) ((b)-(a))
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
const int N=1e5+5;
const ll mod=998244353;
const ld pi=3.14159265359;
const ld eps=1e-12;
int dx[]={0,-1,0,1,-1,1,-1,1};
int dy[]={-1,0,1,0,1,-1,-1,1};
ll k,z,m,n,x,y;
ll solverect()
{

}
ll solvecircle()
{

}
void dowork()
{
    ll h,r,ans=0;
    cin>>r>>h;
    ans=(ld)h/(ld)r;
    ans*=2;
    ld t = sqrt(3.0) / 2.0 * (ld) r;
    if(t<=h%r)
    {
        ans += 3;
    }
    else if(2*(h%r)>=r)
    {
        ans+=2;
    }
    else
    {
        ans++;
    }
    cout<<ans<<el;
}
int main()
{
    fast
    //freopen("zone.in","r",stdin);
    //freopen("standard output","w",stdout);
    int t=1;
    //cin>>t;
    for (int i=1;i<=t;i++)
    {
        dowork();
    }
}