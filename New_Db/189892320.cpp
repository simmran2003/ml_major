#include<bits/stdc++.h>
using namespace std;

#define X ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int  long long

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int e = 0; e < n; e++)cin >> arr[e];
    string s;
    cin >> s;
    vector<int> pref(n + 1);
    vector<int> pref1(n + 1);
    vector<int> suff(n + 1);
    vector<int> suff1(n + 1);
    for (int e = 1; e <= n; e++) {
        pref[e] = pref[e - 1] + ((s[e - 1] == 'A') ? arr[e - 1] : 0);
        pref1[e] = pref1[e - 1] + ((s[e - 1] != 'A') ? arr[e - 1] : 0);
        suff[e] = suff[e - 1] + ((s[n - e] == 'A') ? arr[n - e] : 0);
        suff1[e] = suff1[e - 1] + ((s[n - e] != 'A') ? arr[n - e] : 0);
    }
    int ans = 0;
    for (int e = 0; e <= n; e++) {
        ans = max(ans, pref[e] + suff1[n - e]);
        ans = max(ans, pref1[e] + suff[n - e]);
    }
    cout << ans;
}
int32_t main() {
    X;
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
