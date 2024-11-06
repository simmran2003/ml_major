// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define pb push_back
#define debug(x) cout << #x << " " << x << endl
#define all(x) x.begin(),x.end()
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vll vector<ll>
#define vvll vector<vll>
#define ld long double
#define ull unsigned long long
#define vull vector<ull>
#define fi first
#define se second
#define PII pair<int,int>
#define vPII vector<PII>
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define int128 __int128

vector<PII> adj[2505];
int a[2505][2505];


const int MAXN = 2505;
int par[MAXN];

int find(int u){
    return (par[u] == u) ? u : (par[u] = find(par[u]));
}
 
void unite(int u, int v){
    par[find(v)] = find(u);
}

void prep(){
	rep(i,MAXN) par[i] = i;
}

int dist[MAXN][MAXN];

void dfs(int cur, int pre, int start, int mx){
	dist[start][cur] = mx;
	for(const auto &[nxt, w] : adj[cur]){
		if(nxt != pre) 
			dfs(nxt, cur, start, max(mx, w));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << setprecision(16) << fixed;
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	int tt = 1;
	// cin >> tt;
	while(tt--) {
		prep();
		int n; cin >> n;
		rep(i,n) rep(j,n) cin >> a[i][j];
		vector<pair<int,PII>> pq;
		int ok = 1;
		rep(i,n) rep(j,n){
			if(a[i][j] != a[j][i]) ok = 0;
			if(a[i][i] != 0) ok = 0;
		}
		if(!ok){
			cout << "NOT MAGIC\n";
			return 0;
		}
		rep(i,n){
			for(int j = i+1; j < n; j++){
				pq.pb({a[i][j], {i,j}});
			}
		}
		sort(all(pq));
		for(const auto&[w, kr] : pq){
			auto [u,v] = kr;
			if(find(u) != find(v)){
				unite(u,v);
				adj[u].pb({v,w});
				adj[v].pb({u,w});
			}
		}
		rep(i,n){
			dfs(i,-1,i,0);
		}
		rep(i,n){
			rep(j,n){
				if(a[i][j] > dist[i][j]) ok = 0;
			}
		}
		if(!ok){
			cout << "NOT MAGIC";
		}else{
			cout << "MAGIC";
		}
	}
}
