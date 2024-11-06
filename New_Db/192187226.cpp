// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
#define int long long
typedef pair<int, int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define PB push_back
#define F first
#define S second
#define ALL(a) a.begin(), a.end()
#define SET(a, b) memset(a, b, sizeof(a))
#define SZ(a) (int)(a.size())
#define FOR(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define deb(a) cerr << #a << " = " << (a) << endl;
#define deb1(a)                                                        \
    cerr << #a << " = [ ";                                             \
    for (auto it = a.begin(); it != a.end(); it++) cerr << *it << " "; \
    cerr << "]\n";
#define endl "\n"
const long long mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    VI a(n);
    VI freq(1e6 + 5, 0);
    FOR(i, 0, n) {
        cin >> a[i];
        if (a[i] <= 1e6)
            freq[a[i]]++;
    }
    VI dp(m + 5, 0);
    for (int i = m; i >= 1; i--) {
        if (freq[i] > 0) {
            for (int j = i; j <= m; j += i)
                dp[j] += freq[i];
        }
    }
    int ma = 0;
    FOR(i, 1, m + 1) {
        if (dp[ma] < dp[i])
            ma = i;
    }
    if (ma == 0) {
        cout << 1 << " " << 0 << endl;
        return;
    }
    VI ans;
    FOR(i, 0, n) {
        if (ma % a[i] == 0)
            ans.PB(1 + i);
    }
    cout << ma << " " << SZ(ans) << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
}

signed main() {
    fast_io;
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    int totalTests = 1;
    // cin >> totalTests;
    for (int testNo = 1; testNo <= totalTests; testNo++) {
        // cout << "Case #" << testNo << ": ";
        solve();
    }
    return 0;
}