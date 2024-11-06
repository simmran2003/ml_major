#define _USE_MATH_DEFINES
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<climits>
#include<set>
#include<map>
#include<cmath>
#include<iomanip>
#include<iterator>
#include<queue>
#include<stack>
#include<cctype>
#include<deque>
#include<time.h>
#include<bitset>
#include<random>
#include <functional>
#include<unordered_set>
#include<unordered_map>
#include<random>
#include<numeric>
#include<chrono>
#include<sstream>
#include <valarray>
#include<list>
#include<complex>
#include<cassert>


typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define en '\n'
#define forn(i,n) for(int i = 0;i<n;i++)
#define for0(i,n) for(int i = 0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define vec vector
#define veci vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define szof(x) int(x.size())
#define sqr(x) ((x)*(x))
#define debug(x) cerr<<#x<<" = "<<x<<'\n'

using namespace std;

const int INF = 1000000000 + 1e8;
const ll LINF = 2000000000000000000;


template<typename T> void print(vector<T>& a) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << en;
}

template <typename T> void input(vector<T>& a) {
    for (int i = 0; i < a.size(); i++)
        cin >> a[i];
}

const int K = 330;

void solve() {
    int n, m;
    cin >> n >> m;
    vec<int> a(n);
    input(a);

    vec<int> next(n), count(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i + a[i] >= n) {
            next[i] = n;
            count[i] = 1;
        }
        else if (i / K != (i + a[i]) / K) {
            next[i] = i + a[i];
            count[i] = 1;
        }
        else {
            next[i] = next[i + a[i]];
            count[i] = count[i + a[i]] + 1;
        }
    }

    for0(q, m) {
        int type;
        cin >> type;

        if (type == 0) {
            int idx, b;
            cin >> idx >> b;
            idx--;
            a[idx] = b;

            for (int i = idx; i / K == idx / K && i >= 0; i--) {
                if (i + a[i] >= n) {
                    next[i] = n;
                    count[i] = 1;
                }
                else if (i / K != (i + a[i]) / K) {
                    next[i] = i + a[i];
                    count[i] = 1;
                }
                else {
                    next[i] = next[i + a[i]];
                    count[i] = count[i + a[i]] + 1;
                }
            }
        }

        if (type == 1) {
            int i;
            cin >> i;
            i--;

            int ans = 0;
            while (next[i] != n) {
                ans += count[i];
                i = next[i];
            }
            while (i + a[i] < n) {
                i += a[i];
                ans++;
            }
            ans += count[i];
            cout << (i + 1) << " " << ans << en;
        }
    }
}

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int tst = 1;
    //cin >> tst;

    while (tst--)
        solve();
}