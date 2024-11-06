#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1e6 + 10;

int n, m;
int a[N];
int cnt[N], res[N];
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] > m) continue;
		cnt[a[i]]++;
	}
	int mx = 0, lcm = 1;
	for(int i = 1; i <= m; i++) {
		for(int j = i; j <= m; j += i) res[j] += cnt[i];
		if(res[i] > mx) mx = res[i], lcm = i;
	}
	cout << lcm << ' ' << mx << '\n';
	for(int i = 1; i <= n; i++) if(lcm % a[i] == 0) cout << i << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	
	while(t--) {
		solve();
	}
}