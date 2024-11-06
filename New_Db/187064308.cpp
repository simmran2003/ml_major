//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
//#pragma GCC optimize("unroll-loops")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;
#ifdef LOCAL
#define debug(a) cerr << #a << ' ' << a << endl
#else
#define debug(a)
#endif
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define ff first
#define ss second

template<typename T>
bool inmin(T& _x, T _y) {
    return _y < _x ? (_x = _y, true) : false;
}
template<typename T>
bool inmax(T& _x, T _y) {
    return _y > _x ? (_x = _y, true) : false;
}
mt19937 rnd(chrono::duration_cast<chrono::milliseconds> (chrono::system_clock::now().time_since_epoch()).count());

const ll INFl = 2e18;
const int INFi = 1e9 + 10;

inline void solve();
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
#ifdef LOCAL
    freopen("/Users/alexsus/Desktop/solve/read.txt", "r", stdin);
#endif
    //cout << fixed << setprecision(2);
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
}

inline void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    forn(i, n) forn(j, n) {
        cin >> a[i][j];
    }
    forn(i, n) if (a[i][i] != 0) {
        cout << "NOT MAGIC\n";
        return;
    }
    struct event {
        int i, j, c;
        bool operator< (const event &other) const {
            return c < other.c;
        }
    };
    vector<event> b;
    forn(i, n) forn(j, n) b.pb({i, j, a[i][j]});
    sort(all(b));
    vector<bitset<2510>> to(n);
    for (int i = 0; i < sz(b);) {
        int val = b[i].c;
        int j = i;
        while (j < sz(b) && b[j].c == val) {
            auto [x, y, c] = b[j];
            auto it = to[x] & to[y];
            if (it.any()) {
                cout << "NOT MAGIC\n";
                return;
            }
            ++j;
        }
        j = i;
        while (j < sz(b) && b[j].c == val) {
            auto [x, y, c] = b[j];
            to[x][y] = true;
            ++j;
        }
        i = j;
    }
    cout << "MAGIC\n";
}