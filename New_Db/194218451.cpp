#include<bits/stdc++.h>
#define ff             first
#define ss             second
#define pob            pop_back
#define pof            pop_front
#define pb             push_back
#define pf             push_front
#define lb             lower_bound
#define ub             upper_bound
#define pii            pair<int,int>
#define sz(x)          (ll)(x.size())
#define all(x)         x.begin(),x.end()

using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define deb(x...)
#endif

const int mod = (int)1e9 + 7;

class SparseTable {
public:
    int n; vector<int> lg;
    vector<vector<int>> table;

    void build(vector<int> &euler, vector<int> &depth) {
        n = sz(euler); lg.resize(n + 1); lg[1] = 0;

        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

        table.resize(lg[n] + 1), table[0] = euler;

        for (int j = 1; j <= lg[n]; j++) {
            table[j].resize(n - (1 << j) + 1);
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                int left = table[j - 1][i], right = table[j - 1][i + (1 << (j - 1))];
                table[j][i] = (depth[left] < depth[right] ? left : right);
            }
        }
    }

    int query(int l, int r, vector<int> &depth) {
        int j = lg[r - l + 1];
        int left = table[j][l], right = table[j][r - (1 << j) + 1];
        return (depth[left] < depth[right] ? left : right);
    }
};

class LCA {
public:
    int timer = 0;
    vector<int> depth, euler, first_occurrence, tin, tout, parent;
    SparseTable st;

    void build(int root, int n, vector<int> adj[]) {
        tin.resize(n), tout.resize(n);
        depth.resize(n), parent.resize(n);
        first_occurrence.resize(n);

        dfs(root, -1, adj, 0);
        st.build(euler, depth);
    }

    void dfs(int v, int p, vector<int> adj[], int d) {
        tin[v] = ++timer;

        euler.push_back(v);
        depth[v] = d, parent[v] = p;
        first_occurrence[v] = sz(euler) - 1;

        for (auto &u : adj[v]) {
            if (u == p) continue;
            dfs(u, v, adj, d + 1);
            euler.push_back(v);
        }

        tout[v] = ++timer;
    }

    inline int getLCA(int a, int b) {
        int l = first_occurrence[a], r = first_occurrence[b];
        if (l > r) swap(l, r);
        return st.query(l, r, depth);
    }

    inline int getDistance(int a, int b) {
        return depth[a] + depth[b] - 2 * depth[getLCA(a, b)];
    }

    inline bool isAncestor(int a, int b) {//whether a is ancestor of b
        return (tin[a] <= tin[b] and tout[b] <= tout[a]);
    }

    inline bool onPath(int x, int a, int b) { //whether x is on path from a to b
        return ((isAncestor(x, a) or isAncestor(x, b)) and isAncestor(getLCA(a, b), x));
    }
};

class CentroidTree {
public:
    vector<int> siz, removed, centroid_parent, best;
    LCA L;

    void build(int root, int n, vector<int> adj[]) {
        siz.assign(n, 0), removed.assign(n, 0), centroid_parent.assign(n, -1);
        best.assign(n, n + 1);//remeber to change this

        function<void(int, int)> dfs1 = [&](int v, int p) {//find siz
            siz[v] = 1;
            for (auto &u : adj[v]) {
                if (u == p or removed[u]) continue;
                dfs1(u, v), siz[v] += siz[u];
            }
        };

        function<int(int, int, int)> dfs2 = [&](int v, int p, int m) {//find centroid for a tree
            for (auto &u : adj[v]) {
                if (u == p or removed[u]) continue;
                if (siz[u] > m / 2) return dfs2(u, v, m);
            }
            return v;
        };

        function<int(int)> dfs3 = [&](int v) {//assgin centroid parent
            dfs1(v, -1);
            int c = dfs2(v, -1, siz[v]);
            removed[c] = 1;

            for (auto &u : adj[c]) {
                if (removed[u]) continue;
                centroid_parent[dfs3(u)] = c;
            }
            return c;
        };

        dfs3(root);
        L.build(root, n, adj);
    }

    int query(int v) {
        int ans = best[v], curr = centroid_parent[v];

        while (curr != -1) {
            ans = min(ans, best[curr] + L.getDistance(curr, v));
            curr = centroid_parent[curr];
        }
        return ans;
    }

    void update(int v) {
        best[v] = 0;
        int curr = centroid_parent[v];
        while (curr != -1) {
            best[curr] = min(best[curr], L.getDistance(curr, v));
            curr = centroid_parent[curr];
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    CentroidTree C;
    C.build(0, n, adj), C.update(0);

    for (int i = 0; i < m; i++) {
        int op, v;
        cin >> op >> v;
        op--, v--;
        if (op) cout << C.query(v) << "\n";
        else C.update(v);
    }
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef NCR
    initiate();
#endif

#ifdef Sieve
    initiate();
#endif

#ifdef LinearSieve
    initiate();
#endif

    int TESTS = 1;//cin >> TESTS;
    for (int T = 1; T <= TESTS; T++) {
        solve();
    }

    return 0;
}