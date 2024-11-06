#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<array <int, 3>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define AboTaha_on_da_code ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second

const int dx[8]={0, 0, 1, -1, 1, -1, -1, 1}, dy[8]={1, -1, 0, 0, 1, -1, 1, -1};
const int M = 1e9+7, M2 = 998244353;
const double EPS = 1e-9;

void burn(int tc)
{
    ll r, h; cin >> r >> h;
    ll ans = h/r*2+1;
    h%=r;
    if (4*h*h >= 3*r*r) ans+=2;
    else if (2*h >= r) ans++;
    cout << ans;
}

int main()
{
    AboTaha_on_da_code

//    freopen("Ain.txt", "r", stdin);
//    freopen("Aout.txt", "w", stdout);

    int T = 1; // cin >> T;

    for (int i = 1; i <= T; i++) {
//        cout << "Case #" << i << ": ";
        burn(i);
        cout << '\n';
    }
    return 0;
}