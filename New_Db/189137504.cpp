#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e6 + 10, mod = 1e9 + 7;
ll n, m;
ll q[N],w[N];
int st[N];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(2);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> q[i];
		if(q[i]>m)continue;
		w[q[i]]++;
	}
	for(ll i=1;i<=m;i++){
		for(ll j=i;j<=m;j+=i){
			st[j]+=w[i];
		}
	}
	int ans = 0;
	ll d = 1;
	for (int i = 1; i <= m; i++) {
		if (ans < st[i]) {
			ans = st[i];
			d=i;
		}
	}
	cout << d << " ";
	cout << ans << '\n';
	for(int i=1;i<=n;i++){
		if(d%q[i]==0){
			cout<<i<<" ";
		}
	}
	return 0;
}
