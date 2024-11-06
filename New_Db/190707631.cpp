#include <bits/stdc++.h>

#define rep(a, b) for (num a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define many int t; cin >> t; while (t--)
#define yesno cout << (solve() ? "YES" : "NO") << '\n'
#define print cout << solve() << '\n'
#define call solve()

using namespace std;

using num = long long int;
using seq = vector<num>;
using par = pair<num,num>;
using Graph = vector<vector<num>>;
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T,U>& p) { return os << p.first << ' ' << p.second; }
template<typename T, typename U> istream& operator>>(istream& is, pair<T,U>& p) { return is >> p.first >> p.second; }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) { for (auto& e : v) os << e << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& e : v) is >> e; return is; }
void read(Graph& adj, num m, bool directed = false) { rep(i, m) { num u, v; cin >> u >> v; --u, --v; adj[u].push_back(v); if (!directed) adj[v].push_back(u); } }

struct UnionFind {
    vector<int> parent, size;
    UnionFind(int n) : parent(n), size(n, 1) {
        iota(all(parent), 0);
    }

    int find(num x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    int merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y])
                swap(x, y);
            parent[y] = x;
            size[x] += size[y];
        }
        return x;
    }
};

class BinaryLifting {
    // Graph may be a forest, but queries must be in the same tree
    using WGraph = vector<vector<par>>;
    num n, logn;
    Graph ancestor, lift;
    seq depth;
    // Commutative, associative
    static const num neutral = numeric_limits<num>::min();
    static num f(num x, num y) {
        return max(x, y);
    }

    void dfs(num node, const WGraph& adj) {
        for (auto [child, weight] : adj[node])
            if (depth[child] == -1)
                ancestor[child][0] = node,
                lift[child][0] = weight,
                depth[child] = depth[node] + 1,
                        dfs(child, adj);
    }
public:
    explicit BinaryLifting(const WGraph& adj) : n(adj.size()), logn(log2(n) + 1), ancestor(n, seq(logn)), lift(n, seq(logn)), depth(n, -1) {
        rep(i, n)
            if (depth[i] == -1)
                depth[i] = 0, ancestor[i][0] = i, dfs(i, adj);

        rep(j, logn - 1)
            rep(i, n)
                ancestor[i][j + 1] = ancestor[ancestor[i][j]][j],
                        lift[i][j + 1] = f(lift[i][j], lift[ancestor[i][j]][j]);
    }

    num query(num u, num v) const {
        if (depth[u] < depth[v])
            swap(u, v);
        num ans = neutral;
        num diff = depth[u] - depth[v];
        rep(j, logn)
            if (diff & (1 << j))
                ans = f(ans, lift[u][j]),
                        u = ancestor[u][j];
        if (u == v)
            return ans;
        for (num j = logn - 1; j >= 0; j--)
            if (ancestor[u][j] != ancestor[v][j])
                ans = f(ans, f(lift[u][j], lift[v][j])),
                u = ancestor[u][j],
                v = ancestor[v][j];
        return f(ans, f(lift[u][0], lift[v][0]));
    }
};

bool solve() {
    num n;
    cin >> n;
    Graph a(n, seq(n));
    cin >> a;
    rep(i, n)
        if (a[i][i])
            return false;
    rep(i, n)
        rep(j, n)
            if (a[i][j] != a[j][i])
                return false;
    using tri = tuple<num,num,num>;
    vector<tri> edges;
    rep(i, n)
        rep(j, i)
            edges.emplace_back(a[i][j], i, j);
    UnionFind uf(n);
    sort(all(edges));
    vector<vector<par>> adj(n);
    for (auto [w, u, v] : edges)
        if (uf.find(u) != uf.find(v))
            uf.merge(u, v), adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
    BinaryLifting bl(adj);
    rep(i, n)
        rep(j, i)
            if (bl.query(i, j) != a[i][j])
                return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << (solve() ? "MAGIC" : "NOT MAGIC") << '\n';
    return 0;
}
