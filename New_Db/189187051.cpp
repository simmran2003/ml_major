// LUOGU_RID: 99755598
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 3e5 + 10;

string s[N];
void solve() {
	int n, p;
	cin >> n >> p;
	ll m = 0, d = 0;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = n; i >= 1; i--) {
		if(s[i] == "half") m = m * 2;
		else m = m * 2 + 1, d += p / 2;
	}
	cout << m * p - d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	
	while(t--) {
		solve();
	}
}