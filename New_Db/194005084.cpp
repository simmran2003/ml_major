#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int grp = n / 3;
    vector<int> v[3];

    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < grp; j++)
        {
            v[i].push_back(arr[k]);
            k++;
        }
    }

    int cnt = 0;

    int ans[grp][3];

    for (int i = 0; i < grp; i++)
    {
        int a = v[0][i];
        int b = v[1][i];
        int c = v[2][i];
        int arr2[3] = {a, b, c};
        sort(arr2, arr2 + 3);
        a = arr2[0];
        b = arr2[1];
        c = arr2[2];

        if (c > b && b > a && c % b == 0 && b % a == 0)
        {
            cnt++;
            ans[i][0] = a;
            ans[i][1] = b;
            ans[i][2] = c;
        }
    }

    if (cnt == grp)
    {
        for (int i = 0; i < grp; i++)
        {
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
        }
        return;
    }

    cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
