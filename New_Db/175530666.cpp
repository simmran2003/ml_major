#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ld h, r;
    cin >> r >> h;
    ll k = floor(2 * h / (r * sqrtl(3)));
    ll ans = (k / 2) * 3 + 2 * (k % 2) + 1;
    ans = max(ans, (ll)floor((h + r / 2) / r) * 2);
    ans = max(ans, (ll)floor((h + r * (2 - sqrtl(3)) / 2) / r) * 2 + 1);
    cout << ans;
}