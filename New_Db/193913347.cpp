#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
int nxt() { int x; cin >> x; return x; }
#define all(x) (x).begin(), (x).end()

using ii = array<int, 2>;
using vii = vector<ii>;

struct binary_lift {
  vii time;
  vvi up;
  vi h;

  binary_lift(const vvi& adj)
      : time(1 + adj.size()),
        up(1 + adj.size(), vi(bit_width(1 + adj.size()) + 1, adj.size())),
        h(1 + adj.size()) {
    int timer = 0;
    auto Dfs = [&](auto self, int u, int p) -> void {
      time[u][0] = ++timer;
      h[u] = h[p] + 1;
      up[u][0] = p;
      for (int i = 1; i < (int)up[u].size(); ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
      }
      for (int v : adj[u]) {
        if (v != p) self(self, v, u);
      }
      time[u][1] = ++timer;
    };
    int n = adj.size();
    time[n][0] = ++timer;
    Dfs(Dfs, 0, n);
    time[n][1] = ++timer;
  }

  // Copy as many as needed:

  bool is_ancestor(int u, int v) {
    return time[u][0] <= time[v][0] && time[v][1] <= time[u][1];
  }

  int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = (int)up[u].size() - 1; i >= 0; --i) {
      if (!is_ancestor(up[u][i], v)) {
        u = up[u][i];
      }
    }
    return up[u][0];
  }

  int dist(int u, int v) { return h[u] + h[v] - 2 * h[lca(u, v)]; }

  int parent(int u, int d) {
    for (int i = 0; d > 0; ++i, d >>= 1) {
      if (d & 1) u = up[u][i];
    }
    return u;
  }

  // node at distance d from u in the path u->v
  int trav(int u, int v, int d) {
    int p = lca(u, v);
    if (d <= h[u] - h[p]) {
      return parent(u, d);
    } else {
      return parent(v, h[u] + h[v] - 2 * h[p] - d);
    }
  }

  // Representation of path via $\bigO(\log \mathrm{len})$ pairs $(u, i)$,
  // each representing the segment $[u, \mathrm{parent}^{2^i}(u))$.
  vii compressed_path(int u, int v) {
    vii path;
    int p = lca(u, v);
    for (int i = 0, d = dist(u, p); d > 0; ++i, d >>= 1) {
      if (d & 1) {
        path.push_back({u, i});
        u = up[u][i];
      }
    }
    for (int i = 0, d = dist(v, p) + 1; d > 0; ++i, d >>= 1) {
      if (d & 1) {
        path.push_back({v, i});
        v = up[v][i];
      }
    }
    return path;
  }
};

vi centroid_decomposition(const vvi& adj) {
  vi sz(adj.size()), parent(adj.size(), -2);
  auto Size = [&](auto self, int u, int p = -1) -> int {
    if (parent[u] != -2) return 0;
    sz[u] = 1;
    for (int v : adj[u]) {
      if (v != p) sz[u] += self(self, v, u);
    }
    return sz[u];
  };
  auto FindCentroid = [&](auto self, int num, int u, int p = -1) -> int {
    for (int v : adj[u]) {
      if (v != p && parent[v] == -2 && sz[v] > num / 2) {
        return self(self, num, v, u);
      }
    }
    return u;
  };
  auto Decompose = [&](auto self, int u, int p = -1) -> void {
    Size(Size, u);
    int c = FindCentroid(FindCentroid, sz[u], u, -1);
    parent[c] = p;
    for (int v : adj[c]) {
      if (parent[v] == -2) self(self, v, c);
    }
  };
  Decompose(Decompose, 0);
  return parent;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n = nxt(), q = nxt();
  vvi adj(n);
  for (int e = 0; e < n - 1; ++e) {
    int u = nxt() - 1, v = nxt() - 1;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  binary_lift lift(adj);
  vi cd = centroid_decomposition(adj);
  vi dp(n, 1e9);
  for (int v = 0; v != -1; v = cd[v]) {
    dp[v] = min(dp[v], lift.dist(v, 0));
  }
  while (q--) { 
    int t = nxt(), u = nxt() - 1;
    if (t == 1) {
      for (int v = u; v != -1; v = cd[v]) {
        dp[v] = min(dp[v], lift.dist(u, v));
      }
    } else {
      int ans = 1e9;
      for (int v = u; v != -1; v = cd[v]) {
        ans = min(ans, dp[v] + lift.dist(u, v));
      }
      cout << ans << '\n';
    }
  }
}
