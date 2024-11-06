//#define __GLIBCXX_DEBUG 1

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 2;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oredered_set;


#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fastIo(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a)
#define F first
#define S second
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define eb(a) emplace_back(a)
#define dbg(a) cerr << #a << "=" << a << "\n";
#define dbg1(a) cerr << #a << " = [ "; for (auto& _ : a) cerr << _ << " "; cerr << "]" << "\n";
#define dbg2(a) cerr << #a << " = [ "; for (auto& _ : a) cerr << "(" << _.F << " " << _.S << ") "; cerr << "\n";
#define int long long


int ad(const int &a, const int &b, const int &mod) {
    if (a + b >= mod) return a + b - mod;
    return a + b;
}

int sub(const int &a, const int &b, const int &mod) {
    if (a < b) return a - b + mod;
    return a - b;
}

int multi(const int &a, const int &b, const int &mod) {
    return 1ll * a * b % mod;
}


int ask(int x) {
    cout << "- " << x << endl;
    int ans;
    cin >> ans;
    return ans;
}

void answer(int x) {
    cout << "! " << x << endl;
}

const int sq = 300;

int nxt[MAXN], cnt[MAXN], power[MAXN], last[MAXN];

signed main() {
    fastIo(0);
    //cout << fixed << setprecision(6);

    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < n ; ++i) cin >> power[i];
    for (int i = n - 1 ; i >= 0 ; --i) {
        int j = min(n, power[i] + i);
        int idxi = i / sq, idxj = j / sq;
        if (j == n) {
            nxt[i] = n;
            cnt[i] = 1;
            last[i] = i;
        } else if (idxi == idxj) {
            nxt[i] = nxt[j];
            last[i] = last[j];
            cnt[i] = cnt[j] + 1;
        } else {
            last[i] = i;
            nxt[i] = j;
            cnt[i] = 1;
        }
    }
    for (int x = 0 ; x < m ; ++x) {
        int c, a, b;
        cin >> c >> a;
        a--;
        if (c) {
            int res = 0, ans = a;
            while (a != n) {
//                dbg(a);
//                dbg(nxt[a]);
                ans = last[a];
                res += cnt[a];
                a = nxt[a];
            }
            cout << ans + 1 << " " << res << "\n";
        } else {
            cin >> b;
            power[a] = b;
            for (int i = a ; i >= a / sq * sq ; --i) {
                int j = min(n, power[i] + i);
                int idxi = i / sq, idxj = j / sq;
                if (j == n) {
                    nxt[i] = n;
                    cnt[i] = 1;
                    last[i] = i;
                } else if (idxi == idxj) {
                    nxt[i] = nxt[j];
                    cnt[i] = cnt[j] + 1;
                    last[i] = last[j];
                } else {
                    last[i] = i;
                    nxt[i] = j;
                    cnt[i] = 1;
                }
            }
        }
    }
}
