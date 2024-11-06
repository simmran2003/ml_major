#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

constexpr int N = 100005;
constexpr int LOG_N = 20;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
set<int> g[N];
int par[LOG_N][N];
vector<int> cd[N];
int sz[N], fa[N], ans[N], tin[N], tout[N], dep[N];
int dfs_timer = 0;

void pre_dfs(int u, int p, int d) {
  par[0][u] = p;
  tin[u] = ++dfs_timer;
  dep[u] = d;
  for (auto& v : g[u]) {
    if (v == p) continue;
    pre_dfs(v, u, d + 1);
  }
  tout[u] = dfs_timer;
}

bool is_ancs(int u, int v) {
  return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}

int lca(int u, int v) {
  if (is_ancs(u, v)) return u;
  if (is_ancs(v, u)) return v;
  for (int j = LOG_N - 1; j >= 0; j--) {
    if (!is_ancs(par[j][v], u)) v = par[j][v];
  }
  return par[0][v];
}

int dist(int u, int v) {
  return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

void dfs(int u, int p) {
  sz[u] = 1;
  for (auto& v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}

int centroid(int u, int p, int n) {
  for (auto& v : g[u]) {
    if (v == p) continue;
    if (sz[v] > n / 2) return centroid(v, u, n);
  }
  return u;
}

void decompose(int u, int p) {
  dfs(u, p);
  int n = sz[u];
  int c = centroid(u, p, n);
  if (p != -1) {
    fa[c] = p;
    cd[p].emplace_back(c);
    cd[c].emplace_back(p);
  } else fa[c] = c;
  vector<int> tmp(g[c].begin(), g[c].end());
  for (auto& v : tmp) {
    g[c].erase(v);
    g[v].erase(c);
    decompose(v, c);
  }
}

void update(int v) {
  int u = v;
  while (true) {
    ans[u] = min(ans[u], dist(u, v));
    if (u == fa[u]) break;
    u = fa[u];
  }
}

int get(int v) {
  int res = INF;
  int u = v;
  while (true) {
    res = min(res, ans[u] + dist(u, v));
    if (u == fa[u]) break;
    u = fa[u];
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].insert(v);
    g[v].insert(u);
  }
  pre_dfs(1, 1, 0);
  for (int j = 1; j < LOG_N; j++) {
    for (int i = 1; i <= n; i++) {
      par[j][i] = par[j - 1][par[j - 1][i]];
    }
  }
  decompose(1, -1);
  memset(ans, 0x3f, sizeof(ans));
  update(1);
  while (m--) {
    int t, v;
    cin >> t >> v;
    if (t == 1) {
      update(v);
    } else if (t == 2) {
      cout << get(v) << '\n';
    }
  }
  return 0;
}
