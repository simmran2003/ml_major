#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 100010;
int d[8];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        d[x]++;
    }

    vector<int> ans;
    for(int i = 0; i < d[1]; i++)
    {
        
        if(d[2] && d[4])
        {
            ans.push_back(1);
            ans.push_back(2);
            ans.push_back(4);
            d[2]--, d[4]--;

            continue;
        }

        if(d[2] && d[6])
        {
            ans.push_back(1);
            ans.push_back(2);
            ans.push_back(6);
            d[2]--, d[6]--;

            continue;
        }

        if(d[3] && d[6])
        {
            ans.push_back(1);
            ans.push_back(3);
            ans.push_back(6);
            d[3]--, d[6]--;

            continue;
        }

        cout << -1;
        return 0;
    }

    for(int i = 2; i <= 7; i++)
    {
        if(d[i])
        {
            cout << -1;
            return 0;
        }
    }

    for(int i = 0; i < ans.size(); i += 3)
    {
        cout << ans[i] << " " << ans[i + 1] << " " << ans[i + 2] << '\n';
    }

    return 0;
}