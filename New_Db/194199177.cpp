// LUOGU_RID: 102527342
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int ch[N][2], fa[N], siz[N], rev[N], n, m, a[N], pid[N], id[N];
inline bool is_root(int x) {
	return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
}
inline bool get(int x) {
	return ch[fa[x]][1] == x;
}
inline void pushup(int x) {
	pid[x] = max({id[x], pid[ch[x][0]], pid[ch[x][1]]});
	siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
}
inline void pushdown(int x) {
	if (rev[x]) {
		int &ls = ch[x][0], &rs = ch[x][1];
		swap(ls, rs);
		if (ls)
			rev[ls] ^= 1;
		if (rs)
			rev[rs] ^= 1;
		rev[x] = 0;
	}
}
inline void pushall(int x) {
	if (!is_root(x))
		pushall(fa[x]);
	pushdown(x);
}
inline void rorate(int x) {
	int y = fa[x], z = fa[y], chx = get(x), chy = get(y), &t = ch[x][chx ^ 1];
	fa[x] = z;
	if (!is_root(y))
		ch[z][chy] = x;
	ch[y][chx] = t, fa[t] = y, t = y, fa[y] = x;
	pushup(y);
}
inline void splay(int x) {
	pushall(x);
	for (int f; f = fa[x], !is_root(x); rorate(x)) {
		if (!is_root(f))
			rorate(get(f) == get(x) ? f : x);
	}
	pushup(x);
}
inline void access(int x) {
	for (int f = 0; x; f = x, x = fa[x]) {
		splay(x), ch[x][1] = f, pushup(x);
	}
}
inline void make_root(int x) {
	access(x), splay(x);
	rev[x] ^= 1;
}
inline int find_root(int x) {
	access(x), splay(x);
	while (ch[x][0])
		pushdown(x), x = ch[x][0];
	splay(x);
	return x;
}
inline void split(int x, int y) {
	make_root(x);
	access(y), splay(y);
}
inline void link(int x, int y) {
	make_root(x);
	fa[x] = y;
}
inline void cut(int x, int y) {
	make_root(x);
	if (find_root(y) == x && fa[y] == x && ch[x][1] == y) {
		ch[x][1] = fa[y] = 0;
		pushup(x);
	}
}
signed main() {
//	freopen("P3203_1.in", "r", stdin);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		siz[i] = 1, pid[i] = id[i] = i;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i + a[i] > n)
			link(i, n + 1);
		else
			link(i, i + a[i]);
	}
	for (int i = 1, op, v, k; i <= m; i++) {
		cin >> op >> v;
		if (op == 1) {
			split(v, n + 1);
			cout << pid[n + 1] << ' ' << siz[n + 1] - 1 << '\n';
		} else {
			cin >> k;
			if (v + a[v] > n)
				cut(v, n + 1);
			else
				cut(v, v + a[v]);
			a[v] = k;
			if (v + a[v] > n)
				link(v, n + 1);
			else
				link(v, v + a[v]);
		}
	}
	return 0;
}