#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <stack>
#include <deque>
#define ff first
#define ss second
using namespace std;
using ll = long long;
int const N = 100005;
vector<int> v[N];
int xorut[N], sz[N], up[N][20], tin[N], tout[N], t = 1;

void lcadfs(int g, int p, int xo)
{
	tin[g] = t++;
	xorut[g] = xo;
	up[g][0] = p;
	for (int i = 1; i <= 18; i++)
	{
		up[g][i] = up[up[g][i - 1]][i - 1];
	}
	for (auto to : v[g])
	{
		if (to != p)
			lcadfs(to, g, xo + 1);
	}
	tout[g] = t++;
}

bool ispapa(int a, int b)
{
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int get_lca(int a, int b)
{
	if (ispapa(a, b))return a;
	if(ispapa(b, a))return b;
	int get = b;
	for (int i = 18; i >= 0; i--)
	{
		if (ispapa(up[get][i], a) == 0)
			get = up[get][i];
	}
	return up[get][0];
}

int mig[N], color[N], chap;

void get_sz(int g, int p)
{
	chap++;
	sz[g] = 1;
	for (auto to : v[g])
	{
		if (to != p && color[to] != 1)
		{
			get_sz(to, g);
			sz[g] += sz[to];
		}
	}
}

int get_cdc(int g, int p)
{
	for (auto to : v[g])
	{
		if (to != p && color[to] != 1 && sz[to] > chap / 2)
			return get_cdc(to, g);
	}
	return g;
}

int papa[N];

void centroiddec(int g)
{
	color[g] = 1;
	for (auto to : v[g])
	{
		if (color[to] != 1)
		{
			chap = 0;
			get_sz(to, g);
			int gag = get_cdc(to, g);
			papa[gag] = g;
			centroiddec(gag);
		}
	}
}

int get_dist(int a, int b)
{
	return xorut[a] + xorut[b] - 2 * xorut[get_lca(a, b)];
}

void solve()
{
	int n, i, j, x, y, m;
	cin >> n >> m;
	for ( i = 0; i < n - 1; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	lcadfs(1, 1, 1);
	get_sz(1, -1);
	int koren = get_cdc(1, -1);
	papa[koren] = -1;
	centroiddec(koren);
	int oo = 1000000000;
	for ( i = 0; i <= n; i++)
	{
		mig[i] = oo;
	}
	int poxel = 1;
	while (poxel != -1)
	{
		mig[poxel] = min(mig[poxel], get_dist(poxel, 1));
		poxel = papa[poxel];
	}
	for ( i = 0; i < m; i++)
	{
		int c, gg;
		cin >> c >> gg;
		if (c == 1)
		{
			int poxel = gg;
			while (poxel != -1)
			{
				mig[poxel] = min(mig[poxel], get_dist(poxel, gg));
				poxel = papa[poxel];
			}
		}
		else
		{
			int hashvel = gg, ans = oo;
			while (hashvel != -1)
			{
				ans = min(ans, mig[hashvel] + get_dist(hashvel, gg));
				hashvel = papa[hashvel];
			}
			cout << ans << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	//cin >> tt;
	while (tt--)
	{
		solve();	
	}
	return 0;
}