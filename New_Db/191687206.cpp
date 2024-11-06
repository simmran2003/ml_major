// Problem: Sequence
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF13C
// Memory Limit: 62 MB
// Time Limit: 1000 ms

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;

const int MAX = 5E3 + 7;

ll n;
ll a[MAX], b[MAX];
ll S[MAX] = {1 << 30};

int main() {
	cin >> n;
	for (int i = 1; i<= n; i++) cin >> a[i], b[i] = a[i];
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			S[j] += abs(a[i] - b[j]);
			if (j > 1)
				S[j] = min(S[j], S[j - 1]);
		}
	}
	cout << S[n] << endl;
	return 0;
}







