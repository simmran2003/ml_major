#include <bits/stdc++.h>
#define task "a"
#define sz(s) (int)s.size()
#define MASK(n) (1ll << (n))
#define getBit(bit, i) (((bit) >> (i)) & 1)
using namespace std;
using lli = long long;
using pii = pair<int, int>;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

template<class X, class Y> inline bool maximize(X &x, const Y &y) { return (x < y ? x = y, true : false); }

int n, m, a[N], cnt[N], x[N];

void read_input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        if (x[i] < N) a[x[i]]++;
    }
}

void solve() {
    for (int i = 1; i <= m; i++)
        for (int j = i; j <= m; j += i)
            cnt[j] += a[i];
    int val = -1, candi = -1;
    for (int i = 1; i <= m; i++)
        if (maximize(val, cnt[i]))
            candi = i;
    if (candi == -1) { cout << "1 0" << '\n'; return;}
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (candi % x[i] == 0)
            ans.push_back(i);
    cout << candi << " " << sz(ans) << '\n';
    for (auto x: ans) cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t = 1;
    while (t--) {
        read_input();
        solve();
    }
    return 0;
}
