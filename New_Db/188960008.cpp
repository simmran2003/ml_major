#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);
#define print(a) for(auto x:a) {cout << x;} cout << endl;
#define cnt(x) __builtin_popcountll(x)

using namespace std;

const int mod = 998244353;

signed main()
{
    fastio()

    int r, h;
    cin >> r >> h;

    int ans = 2 * (h / r);
    h %= r;

    if (4 * h * h >= 3 * r * r) ans += 3;
    else if (2 * h >= r) ans += 2;
    else ans++;

    cout << ans;

    return 0;
}