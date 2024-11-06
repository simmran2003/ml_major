#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define N 2505
// #define mod 1945555039024054273
#define endl '\n'
// #define int long long
// #define ll long long
// #define ll __int128
// #define double long double
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;

int n, num[N][N];
bitset<2505> a[N], b[N], res;
struct node
{
    int val, x, y;
    bool operator<(const node &tmp) const { return val < tmp.val; }
} s[N * N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> num[i][j];
            s[(i - 1) * n + j] = {num[i][j], i, j};
        }
    for (int i = 1; i <= n; i++)
    {
        if (num[i][i])
        {
            cout << "NOT MAGIC\n";
            return;
        }
        for (int j = 1; j <= n; j++)
        {
            if (num[i][j] != num[j][i])
            {
                cout << "NOT MAGIC\n";
                return;
            }
        }
    }
    sort(s + 1, s + n * n + 1);
    for (int i = 1; i <= n * n;)
    {
        int p = i;
        while (p <= n * n && s[i].val == s[p].val)
        {
            int x = s[p].x, y = s[p].y;
            res = a[x] & b[y];
            if (res.any())
            {
                cout << "NOT MAGIC\n";
                return;
            }
            p++;
        }
        while (i < p)
        {
            int x = s[i].x, y = s[i].y;
            a[x][y] = b[y][x] = 1;
            i++;
        }
    }
    cout << "MAGIC\n";
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