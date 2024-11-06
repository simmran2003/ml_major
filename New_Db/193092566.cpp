#include <bits/stdc++.h>

typedef int32_t ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    const ll c = 990;
    ll nt[n];
    for (ll i = 0; i < n; i++) {
        ll e;
        cin >> e;
        nt[i] = i + e;
    }
    ll nc[n];
    ll cc[n];
    for (ll i = n-1; i >= 0; i--) {
        ll t = nt[i];
        if (t >= n || t / c != i / c) {
            nc[i] = t;
            cc[i] = 1;
        } else {
            nc[i] = nc[t];
            cc[i] = cc[t] + 1;
        }
    }
    for (ll i = 0; i < m; i++) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll x;
            cin >> x;
            x--;
            ll s = 0;
            while (nc[x] < n) {
                s += cc[x];
                x = nc[x];
                //cout << x << ' ';
            } //cout << '\n';
            while (nt[x] < n) {
                s++;
                x = nt[x];
                //cout << x << ' ';
            } //cout << '\n';
            cout << x+1 << ' ' << s+1 << '\n';
            //cout << nt << cc << '\n';
        } else {
            ll x, y;
            cin >> x >> y;
            x--;
            nt[x] = x+y;
            ll l = x/c*c;
            ll r = l + c;
            ll mn = min(n, r);
            for (ll k = x; k >= l; k--) {
                ll t = nt[k];
                if (t >= mn) {
                    nc[k] = t;
                    cc[k] = 1;
                } else {
                    nc[k] = nc[t];
                    cc[k] = cc[t] + 1;
                }
            }
        }
    }
}
