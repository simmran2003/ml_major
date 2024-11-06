#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define N 200005
// #define mod 1000000007
#define endl '\n'
#define int long long
// #define ll long long
// #define ll __int128
#define double long double
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;

int n, p, ans;
string s, t;
void solve()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        if (s == "half")
            t.push_back('0');
        else
            t.push_back('1');
    }
    int tmp = 0;
    while (!t.empty())
        tmp = tmp * 2 + t.back() - '0', t.pop_back();
    while (tmp)
    {
        ans += p * tmp / 2;
        tmp >>= 1;
    }
    cout << ans << endl;
}
signed main()
{
    fastio;
    // freopen("data.in", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    // fclose(stdin);
}