#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < siz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (long long i = (j); i <= (long long)(n); ++i)
#define fn(i, j, n) for (int i = (j); i >= (int)(n); --i)
#define fvec(i, vec) for (auto i : vec)
#define pb push_back
#define MP make_pair
#define mine(x, y, z) min(x, min(y, z))
#define maxe(x, y, z) max(x, max(y, z))
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;

typedef vector<pll> vp;
typedef vector< long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef tree< pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9, N =1e5+5,M=30,MOD=998244353, minOO=LLONG_MIN;

ll n , ancestor[N][M], lvl[N];
vector < ll > g[N];

void dfs( ll node , ll par)
{
    lvl[node] = lvl[par] + 1;
    ancestor[node][0] = par;
    for ( ll j = 1 ; j < M ; j++)
    {
        ll p = ancestor[node][j-1];
        ancestor[node][j] = ancestor[p][j-1];
    }
    for(auto ch : g[node])
    {
        if(ch == par)
            continue;
        dfs(ch,node);
    }
}

ll findKthAncestor( ll u , ll k)		//return zero if k > depth --> call dfs(1,0) in main
{
    for ( ll j = M-1 ; j >= 0 ; j--)
        if(k&(1<<j))
            u = ancestor[u][j];
    return u;
}

ll getLCA( ll u , ll v)
{
    if(lvl[u] < lvl[v])
        swap(u,v);
    u = findKthAncestor(u,lvl[u]-lvl[v]);
    if ( u == v)
        return u;
    for ( ll i = M-1 ; i>= 0 ;i--)
    {
        if(ancestor[u][i] == ancestor[v][i])
            continue;
        u = ancestor[u][i];
        v = ancestor[v][i];
    }
    return ancestor[u][0];
}

ll sz[N];
bool processed[N];

ll get_subtree_sizes(ll node, ll parent = 0) {//(unchageable)
    sz[node] = 1;
    for (ll i : g[node]) if (!processed[i] && i != parent)
            sz[node] += get_subtree_sizes(i, node);
    return sz[node];
}

ll get_centroid(ll desired, ll node, ll parent = 0) {//(unchageable)-->desired is the new size
    for (ll i : g[node])
        if (!processed[i] && i != parent && sz[i] >= desired)
            return get_centroid(desired, i, node);
    return node;
}

vi parent(N);
void centroid_decomp(ll node ,ll par) {
    ll centroid = get_centroid(get_subtree_sizes(node) >> 1, node);//(unchageable)
    processed[centroid] = true;//(unchageable)
    parent[centroid]=par;
    for (ll i : g[centroid])
        if (!processed[i])
            centroid_decomp(i,centroid);//(unchageable)
}
vll best(N,N);
ll get_dist(ll u,ll v){
    ll a= getLCA(u,v);
    return -2*lvl[a]+lvl[u]+lvl[v];
}
void update(ll v) {
    best[v] = 0;

    ll u = v;
    while (parent[u] != -1) {
        u = parent[u];
        best[u] = min(best[u], get_dist(u, v));
    }
}

ll query(ll v) {
    ll ans = best[v];

    ll u = v;
    while (parent[u] != -1) {
        u = parent[u];
        ans = min(ans, best[u] + get_dist(u, v));
    }
    return ans;
}
void func(ll index) {
    // using Centroid decomposition to rearrange the tree so that each update or query only take log(n)
    // use LCA to compute Distance in Log(n);
    //so that each query and update only take O(log(N)^2)
    ll num,q;
    cin>>num>>q;
    fo(i,num-1){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);//// Dont put parent in -1 pls it wont pass case 4
    centroid_decomp(1,-1);
    update(1);
    fo(i,q){
        ll t;cin>>t;
        if(t==1){
            ll u;cin>>u;
            update(u);
        }else{
            ll u;cin>>u;
            cout<<query(u)<<"\n";
        }
    }

}
int main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        func(index++);
    }
    return 0;
}