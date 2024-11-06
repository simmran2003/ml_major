#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e9 + 7;

ll bpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll modinv(ll n, ll p)
{
    return bpow(n, p - 2, p);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;

    ll a[n],b[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }

    sort(b,b+n);
   vector<ll>dp(n);

    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            dp[i]=abs(a[0]-b[i]);
        }
        else dp[i]=min(dp[i-1],abs(a[0]-b[i]));
    }

    for(int i=1;i<n;i++)
    {
        vector<ll>temp(n);
        for(int j=0;j<n;j++)
        {
            if(j==0)
            {
                temp[j]=dp[j]+abs(a[i]-b[j]);
                continue;
            }

            temp[j]=min(temp[j-1],dp[j]+abs(a[i]-b[j]));
        }
        dp=temp;
    }

    cout<<dp[n-1];


    
    return 0;
}