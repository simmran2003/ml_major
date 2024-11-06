#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin >> n;
        priority_queue<int> pq;
        int ans = 0;
        for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                pq.push(x);
                pq.push(x);
                ans += pq.top() - x;
                pq.pop();
        }
        cout << ans << '\n';
        return 0;
}