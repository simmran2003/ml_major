#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define N 1000005
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

int n, k, num[N], f[N];
void solve()
{
    cin >> n >> k;
    map<int, set<int>> mp;
    for (int i = 1; i <= n; i++)
        cin >> num[i], mp[num[i]].insert(i);
    sort(num + 1, num + n + 1);
    if (num[1] > k)
    {
        cout << 1 << " " << 0 << endl;
        return;
    }
    for (int i = 1; i <= n;)
    {
        if (num[i] > k)
            break;
        int p = i;
        while (num[i] == num[p])
            p++;
        for (int j = num[i]; j <= k; j += num[i])
            f[j] += p - i;
        i = p;
    }
    int u = 0;
    for (int i = 1; i <= k; i++)
        if (f[i] > f[u])
            u = i;
    cout << u << " " << f[u] << endl;
    vector<int> ans;
    for (int i = 1; i <= k; i++)
        if (u % i == 0)
            for (auto it = mp[i].begin(); it != mp[i].end(); it++)
                ans.push_back(*it);
    sort(ans.begin(), ans.end());
    for (const int &i : ans)
        cout << i << " ";
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