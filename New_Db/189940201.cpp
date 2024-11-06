#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), cnt(1e6 + 5), ans(1e6 + 5);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < 1e6 + 5)
                cnt[a[i]]++;
        }
        for (int i = 1; i < 1e6 + 5; i++)
        {
            for (int j = i; j < 1e6 + 5; j += i)
            {
                ans[j] += cnt[i];
            }
        }
        int Max = 1;
        for (int i = 1; i <= m; i++)
        {
            if (ans[i] > ans[Max])
            {
                Max = i;
            }
        }
        cout << Max << " " << ans[Max] << endl;
        for (int i = 0; i < n; i++)
        {
            if (Max % a[i] == 0)
            {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}