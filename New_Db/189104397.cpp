#include<bits/stdc++.h>
using namespace std;
string a[500010];
int main() {
  long long qwq = 0, ans = 0, n, p; cin >> n >> p;
  for (int i = n; i >= 1; --i) cin >> a[i];
  for (int i = 1; i <= n; ++i) ans += (qwq = qwq * 2 + (a[i] == "halfplus")) * p / 2;
  cout << ans;
} 