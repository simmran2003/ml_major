#include<bits/stdc++.h>
#define ll long long
#define flot(n) cout << setprecision(n) << setiosflags(ios::fixed) << setiosflags(ios::showpoint)
#define all(a) (a).begin() , (a).end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define piii pair<pii,int>
#define plll pair<pll,ll>
#define R return
#define B break
#define C continue
#define SET(n , i) memset(n , i , sizeof(n))
#define SD ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i , n) for(int i = 0 ; i < n ; i++)
#define repn(i , j , n) for(int i = j ; i < n ; i++)
#define repr(i,n,j) for(int i=n;i>=j;i--)
#define positive(x) ((x%mod+mod)%mod)
#define YES(f)cout<<((f)?"YES":"NO")<<endl
#define F first
#define S second
#define endl '\n'
#define vi vector<int>
//#define int ll
using namespace std;
void readFromFile(string input = "input.txt",string output="output.txt") {
    #ifndef ONLINE_JUDGE
        freopen(input.c_str(),"r",stdin);
        freopen(output.c_str(),"w",stdout);
    #endif
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll x, ll y) {
    return uniform_int_distribution<ll>(x, y)(rng);
}
template <typename T> void Max(T& x,T y){x=max(x,y);}
template <typename T> void Min(T& x,T y){x=min(x,y);}
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-3;
const long double pi =  acos(-1.0);
const int mod = 1e9+9;
const int N =1e5+2;
ll Mul(ll x,ll y,ll mod=mod){R((x%mod)*(y%mod))%mod;}
ll Add(ll x,ll y,ll mod=mod){R((x%mod)+(y%mod)+2ll*mod)%mod;}
int n,m,sq=320,a[N];
pii dp[N];
void calc(int b) {
    int st = max(1,b*sq),en = min(n,st+sq);
    repr(i,en,st) {
        if(a[i]+i > en) dp[i] = {1,i};
        else dp[i] = {dp[a[i]+i].F+1,dp[a[i]+i].S};
    }
}
void solve() {
    cin >> n >> m;
    rep(i,n) cin >> a[i+1];
    rep(i,sq)calc(i);
    while(m--) {
        int ty;cin>>ty;
        if(ty == 1) {
            int x;cin>>x;
            int ans=0,fin=x;
            while(x <= n) {
                ans += dp[x].F;
                fin=dp[x].S;
                x = dp[x].S+a[dp[x].S];
            }
            cout << fin << ' ' << ans << endl;
        }else {
            int x,y;cin>>x>>y;
            a[x]=y;
            calc(x/sq);
        }
    }
}
int32_t main() {
    readFromFile();
    SD;
    int t = 1;
//    cin >> t;
//    scanf("%d",&t);
    rep(i,t) {
        solve();
    }
}
