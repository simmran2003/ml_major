#include <iostream>
#include <bitset>
#include <list>
#include <new>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <random>
#include <utility>
#include <queue>
#include <iterator>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<long long, long long> pii;
typedef long long ll;
//typedef __int128 ll;

#define vec vector
//#define endl '\n'
//#define int long long
#define all(x) x.begin(), x.end()
#define input(x) for (int i = 0; i < x.p(); ++i) cin >> x[i];

const int INF = 1e9 + 7, L = 1e5 + 20, k = 600;

int n, x, y;
vec<int> b(1e4 + 10);
vec<vec<vec<int>>> dp(1e4 + 10, vec<vec<int>>(8, vec<int>(2, -1)));

int pr(int i, int mask, bool flag) {
    int ans = 0;
    if (i == n)
        return mask == 0 && flag;
    int& res = dp[i][mask][flag];
    if (dp[i][mask][flag] != -1) return res;
    res = 0;
    for (int j = 0; j < 3; ++j) {
        if ((b[i] >> j & 1) && (mask >> j & 1)) {
            return res = 0;
        } else {
            ans |= ((b[i] | mask) & (1 << j));
        }
    }
    if ((mask & 1 && ((i == y - 1 || i - 2 == y) && x == 0)) || (mask & 2 && ((i == y - 1 || i - 2 == y) && x == 1))
        || (mask & 4 && ((i == y - 1 || i - 2 == y) && x == 2))) {
        flag = true;
    }
    res += pr(i + 1, ans ^ 7, flag);
    if ((ans & 3) == 0) {
        bool fl = flag;
        fl |= (x == 2 && y == i);
        res += pr(i + 1, (ans | 3) ^ 7, fl);
        if (res >= INF) res -= INF;
    }
    if ((ans & 6) == 0) {
        bool fl = flag;
        fl |= (x == 0 && y == i);
        res += pr(i + 1, (ans | 6) ^ 7, fl);
        if (res >= INF) res -= INF;
    }
    return res;
}

signed main() {
    cin >> n;
    vec<vec<char>> a(3, vec<char>(n));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 'O') {
                x = i, y = j;
            }
            if (a[i][j] == 'X' || a[i][j] == 'O') {
                b[j] |= (1 << i);
            }
        }
    }
    cout << pr(0, 0, 0);
}