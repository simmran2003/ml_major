#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <stack>
#include <cassert>
#include <random>
#include <iostream>

using namespace std;
//#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = (int)1e9 + 7, maxn = (int)1e6, mod = (int)1e9 + 7;

#define debug(x) cerr << (#x) << ": " << (x) << endl
#define fastinp ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int> read_vector(int n) {
    vector <int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    return t;
}

void cout_vector(vector <int> v) {
    for (auto e : v) {
        cout << e << ' ';
    }
    cout << endl;
}

int b;

signed main() {
    fastinp;
    int n, m;
    cin >> n >> m;
    //vector <int> v = read_vector(n);
    b = ceil(sqrt(n));
    vector <vector<int>> sqr/*(ceil(n * 1.0 / (b * 1.0)), vector<int>(b))*/;
    for (int i = 0; i < n;) {
        vector <int> t;
        for (int j = 0; i + j < n && j < b; j++) {
            int a;
            cin >> a;
            t.push_back(a);
        }
        i += b;
        sqr.push_back(t);
    }
    vector <int> next(n, 0), cnt(n, 0); //last elem is needed????
    next.back() = -1;
    cnt.back() = 1;
    for (int i = (int)sqr.size() - 1; i >= 0; i--) {
        for (int j = (int)sqr[i].size() - 1; j >= 0; j--) {
            if (i * b + j + sqr[i][j] >= n) {
                next[i * b + j] = -1;
                cnt[i * b + j] = 1;
            } else {
                if ((i * b + j + sqr[i][j]) / b > i) {
                    next[i * b + j] = i * b + j + sqr[i][j];
                    cnt[i * b + j] = 1;
                } else {
                    next[i * b + j] = next[i * b + j + sqr[i][j]];
                    cnt[i * b + j] = cnt[i * b + j + sqr[i][j]] + 1;
                }
            }
        }
    }
    for (int _ = 0; _ < m; _++) {
        int t;
        cin >> t;
        if (t == 0) {
            int x, y;
            cin >> x >> y;
            x--;
            int i = x / b, j = x - x / b * b;
            sqr[i][j] = y;
            if (i * b + j + sqr[i][j] >= n) {
                next[i * b + j] = -1;
                cnt[i * b + j] = 1;
            } else {
                if ((i * b + j + sqr[i][j]) / b > i) {
                    next[i * b + j] = i * b + j + sqr[i][j];
                    cnt[i * b + j] = 1;
                } else {
                    next[i * b + j] = next[i * b + j + sqr[i][j]];
                    cnt[i * b + j] = cnt[i * b + j + sqr[i][j]] + 1;
                }
            }
            while (--j >= 0) {
                if (i * b + j + sqr[i][j] >= n) {
                    next[i * b + j] = -1;
                    cnt[i * b + j] = 1;
                } else {
                    if ((i * b + j + sqr[i][j]) / b > i) {
                        next[i * b + j] = i * b + j + sqr[i][j];
                        cnt[i * b + j] = 1;
                    } else {
                        next[i * b + j] = next[i * b + j + sqr[i][j]];
                        cnt[i * b + j] = cnt[i * b + j + sqr[i][j]] + 1;
                    }
                }
            }
        } else {
            int x;
            cin >> x;
            x--;
            int count = 0, answ = x;
            int i = x / b, j = x - x / b * b;
            while (true) {
                if (next[answ] == -1) {
                    count += cnt[answ];
                    while (answ + sqr[answ / b][answ - answ / b * b] < n) {
                        answ += sqr[answ / b][answ - answ / b * b];
                    }
                    break;
                }
                count += cnt[answ];
                answ = next[answ];
            }
            cout << answ + 1 << ' ' << count << endl;
        }
    }
}
