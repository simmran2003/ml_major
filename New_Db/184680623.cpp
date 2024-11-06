#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, s, f;
    cin >> n >> m >> s >> f;
    ll t[m], l[m], r[m];
    pair<ll, ll> p[m];
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < m; i++)
    {
        cin >> t[i] >> l[i] >> r[i];
        p[i].first = l[i];
        p[i].second = r[i];
        mp[t[i]]++;
    }
    int k = 0;
    if (s < f)
    {
        string sol = "";
        int pt1 = s, pt2 = f;
        int cnt = 0;
        while (pt1 != pt2)
        {
            if (mp[cnt + 1] > 0)
            {
                if (pt1 <= p[k].second and pt1 >= p[k].first)
                {
                    sol.push_back('X');
                    k++;
                }
                else if ((pt1 + 1 <= p[k].second and pt1 + 1 >= p[k].first) and pt1 != n)
                {
                    sol.push_back('X');
                    k++;
                }
                else
                {
                    sol.push_back('R');
                    pt1++;
                    k++;
                }
            }
            else
            {
                sol.push_back('R');
                pt1++;
            }
            cnt++;
        }
        cout << sol << endl;
    }
    else
    {
        string sol = "";
        int pt1 = s, pt2 = f;
        int cnt = 0;
        while (pt1 != pt2)
        {
            if (mp[cnt + 1] > 0)
            {
                if (pt1 <= p[k].second and pt1 >= p[k].first)
                {
                    sol.push_back('X');
                    k++;
                }
                else if ((pt1 - 1 <= p[k].second and pt1 - 1 >= p[k].first) and pt1 != 1)
                {
                    sol.push_back('X');
                    k++;
                }
                else
                {
                    sol.push_back('L');
                    pt1--;
                    k++;
                }
            }
            else
            {
                sol.push_back('L');
                pt1--;
            }
            cnt++;
        }
        cout << sol << endl;
    }
    return 0;
}