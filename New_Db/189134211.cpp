#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e6 + 10, mod = 1e9 + 7;
ll n, m;
string q[N];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(2);
	string a, b;
	a = "half";
	b = "halfplus";
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> q[i];
	}
	ll now = 0;
	ll p=0;
	for (int i = n; i; i--) {
		now *= 2;
		if (q[i] == b) {
			now++;
			p++;
		}
	}
	cout<<now*m-m/2*p;
	return 0;
}
