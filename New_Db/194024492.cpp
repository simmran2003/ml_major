#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <string>
#include <sstream>



using namespace std;
//#define int long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define F first
#define S second

typedef long long int ll;
const int N = 1e7+7;
const int mod=1e9+7;
//cout<<fixed<<setprecision(10);
/*void subarray(){
    int n,ans;
    ll t;
    cin>>n>>t;
    int a[n+5],s[n+5]={0};
    for(int i=1; i<=n; ++i)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1; i<=n; ++i)
    {
        if(a[i]>t)continue;
        int l=i,r=n;
        while(l<r)
        {
            int mid=(l+r)>>1;
            mid++;
            if(s[mid]-s[i-1]<=t)l=mid;
            else r=mid-1;
        }
        ans=max(ans,l-i+1);


    }
    cout<<ans;

}
*/
/*void E2()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>v;
    ll ans=0;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++)
    {
        auto idx=upper_bound(v.begin(),v.end(),v[i]+k)-v.begin();
        idx-=1;
        if(idx-i+1>=m)
            ans=(ans%MOD+ncr(idx-i,m-1)%MOD)%MOD;



    }
    cout<<ans<<'\n';

}*/

ll power(ll a,ll b)
{

    if(b==0)
    {
        return 1;
    }
    ll s= power(a,b/2);
    return(b&1 ?a*s*s:s*s);
}

ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}


const int D = 1e5 + 5;
int prime[D];

void Sieve()
{
    for (int i = 2; i < D; ++i)
    {
        if (!prime[i])
        {
            for (int j = i + i; j <= D; j += i)
            {
                prime[j]=1;
            }
        }
    }
}
ll fact[1000006],inv[1000006];
ll mul(ll a,ll b)
{
    return (a%mod * b%mod)%mod;
}
ll npr(ll n, ll r)
{
    return mul(fact[n],inv[n-r]);
}
ll ncr(ll n, ll r)
{
    return mul(fact[n],mul(inv[n-r],inv[r]));
}
ll fast_power(ll base,ll exp)
{
    if(exp==0)
        return 1;
    ll ans = fast_power(base,exp/2);
    ans = mul(ans,ans);
    if(exp%2!=0)
        ans = mul(ans,base);
    return ans;
}
void calcFacAndInv(ll n)
{
    fact[0] = inv[0] = 1;
    for(ll i=1; i<=n; i++)
    {
        fact[i] = (i*fact[i-1])%mod;
        inv[i] = fast_power(fact[i],mod-2);
    }
}

ll prime_factorize(ll n)
{


    // O(sqrt(N))
    for(ll i=2; i*i<=n; i++)
    {
        while(n%(i*i)==0)
        {


            n/=i;
        }
    }
    return n;
}
bool isSquare(ll n)
{
    double sqn=sqrt(n);
    if(sqn==int(sqn))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void work1()
{
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=2; i<n; i++)
    {
        ll k=n;
        while(k)
        {
            ans+=(k%i);
            k/=i;
            // debug(res);
        }
    }
    ll x =n-2;
    ll G =gcd(ans,x);
    cout<<ans/G<<"/"<<x/G;

}
int main()
{
    FIO
    int t=1;
    //calcFacAndInv(100005);
    //cin>>t;
    while(t--)
        work1();

}
