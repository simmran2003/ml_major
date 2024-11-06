    // by ikg
 
#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;

const int E9 = (int) 1e9;
const int N = (int) 5e5+7;
const ll INF = (ll) 1e18;
const ll mod = (ll) E9+7;

int d[N], up[N][20], tin[N], tout[N], timer, len[N], lvl[N];
vector<int> g[N], gc[N];
bool us[N];

void dfs(int v, int p = 1, int lvlt = 0)
{
	tin[v] = timer++;
	lvl[v] = lvlt;
	for (int i = 1; i <= 18; ++i)
	{
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	for (auto to: g[v])
	{
		if (to == p) continue;
		up[to][0] = v;
		len[to] += len[v] + 1;
		dfs(to, v, lvlt + 1);
	}
	tout[v] = timer;
}

void pre_calc(int v, int p = 0)
{
	d[v] = 1;
	for (auto to: g[v])
	{
		if (us[to] || to == p) continue;
		pre_calc(to, v);
		d[v] += d[to];
	}
}

int find_centroid(int v, int p, int c)
{
	for (auto to: g[v])
	{
		if (us[to] || to == p || d[to] + d[to] <= d[c]) continue;
		return find_centroid(to, v, c);
	}
	return v;
}

bool ok(int a, int b)
{
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b)
{
	if (ok(a, b)) return a;
	if (ok(b, a)) return b;
	for (int i = 18; i >= 0; --i)
	{
		if (!ok(up[a][i], b)) a = up[a][i];
	}
	return up[a][0];
}

int dist(int a, int b)
{
	int v = lca(a, b);
	return (lvl[a] - lvl[v]) + (lvl[b] - lvl[v]);
}

void solve(int v, int p = 0)
{
	pre_calc(v);
	v = find_centroid(v, v, v);
	us[v] = true;
	if (p) gc[v].pb(p);
	for (auto to: g[v])
	{
		if (us[to]) continue;
		solve(to, v);
	}
}

void cl(int v, int s)
{
	len[v] = min(len[v], dist(v, s));
	for (auto to: gc[v]) cl(to, s);
}

int calc(int v, int s)
{
	int res = len[v] + dist(v, s);
	for (auto to: gc[v])
	{
		res = min(res, calc(to, s));
	}
	return res;
}

int main()
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	up[1][0] = 1;
	dfs(1);
	solve(1);
	for (int i = 1; i <= q; ++i)
	{
		int t, v;
		cin >> t >> v;
		if (t == 1) cl(v, v);
		else cout << calc(v, v) << '\n';
	}
}

/*
	keep calm
*/