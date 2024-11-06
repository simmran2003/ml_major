// LUOGU_RID: 99731439
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2500 + 10;
int n, a[N][N];
array<int, 3> v[N * N];
bitset<2500> b[N];
void solve() {
	cin >> n;
	int m = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			v[++m] = {a[i][j], i, j};
		}
	}
	sort(v + 1, v + 1 + m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] != a[j][i]) {
				cout << "NOT MAGIC";
				return ;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i][i]) {
			cout << "NOT MAGIC";
			return ;
		}
	}
	for (int i = 1; i <= m; i++) {
		int j = i;
		for(int k = i + 1; k <= m; k++) {
			if(v[k][0] == v[i][0]) j = k;
			else break;
		}
		for(int k = i; k <= j; k++) {
			if((b[v[k][1]] & b[v[k][2]]).any()) {
				cout << "NOT MAGIC";
				return ;
			}
		}
		for(int k = i; k <= j; k++) {
			b[v[k][1]][v[k][2]] = 1;
		}
		i = j;
	}
	cout << "MAGIC";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;

	while (t--) {
		solve();
	}
}