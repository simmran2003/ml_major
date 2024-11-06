#include <bits/stdc++.h>
#define IOS   ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define xs(a) cout<<setiosflags(ios::fixed)<<setprecision(a);
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define mem(a,b) memset(a,b,sizeof(a));
using namespace std;
#define ull unsigned long long
#define ll long long
#define endl '\n'
typedef pair<ll,ll> pll;
const int N=2e6+5;
const int mod=1e9+7;
/*-----------------------------------------------------------------------------------------------*/

int primes[N], cnt;     // primes[]存储所有素数
int minp[N];  
void get_primes(int n) {
    //mul[1]=1;
    for (int i = 2; i <= n; i += 1) {
        if (!minp[i]) primes[++cnt] = i, minp[i] = i ;
        for (int j = 1; primes[j]*i <= n && j<=cnt; j++) {
            minp[primes[j] * i] = primes[j];
            if (minp[i]==primes[j]) break;
        }
    }
}
ll a[N],ct[N],vis[N];
ll val[N];
signed main(){IOS
    get_primes(1e6);
    ll n,m;cin>>n>>m;
    vector<ll>vec;
    FOR(i,1,n){
        cin>>a[i];
        if(a[i]<=m)ct[a[i]]++;
    }
    ll lm=1;
    FOR(i,1,n){
        if(a[i]>m||vis[a[i]])continue;  
        for(int j=a[i];j<=m;j+=a[i]){
            val[j]+=ct[a[i]];
        }
        vis[a[i]]=1;
    }
    ll mx=0;
    FOR(i,1,m){
        if(val[i]>mx){
            mx=val[i];lm=i;
        }
    }
    vector<ll>res;
    FOR(i,1,n)if(lm%a[i]==0)res.push_back(i);
    cout<<lm<<' '<<res.size()<<endl;
    for(auto v:res)cout<<v<<' ';
    cout<<endl;


}