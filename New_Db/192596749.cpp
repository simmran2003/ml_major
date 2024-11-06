#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define in insert
#define er erase
#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set<int> si;
typedef set<ll> sll;
typedef set<pii> spii;
typedef set<pll> spll;
typedef unordered_set<int> usi;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef map<int, int> mi;
typedef map<ll, ll> mll;

const int N = 1e6 + 2;
const int M = 1e5;
const int mod = 1e9 + 7;
const int inf = 2e9 + 3;
const ll INF = 1e18;
const ld pi2 = 2.0 * 3.141592653589793;
const ld pi = 3.141592653589793;
const ld eps = 1e-12;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void files(string s = "main")
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
map<int, pii> wtc;
void solve()
{
    int n, m, s, f, vl, vl1, vl2;
    cin >> n >> m >> s >> f;
    int cur = s;
    for (int i = 0; i < m; ++i)
    {
        cin >> vl >> vl1 >> vl2;
        wtc[vl] = {vl1, vl2};
    }
    int i = 1;
    if (f > s)
    {
        while (cur != f)
        {
            if ((cur+1 >= wtc[i].F && cur+1 <= wtc[i].S) || (cur >= wtc[i].F && cur <= wtc[i].S))
                cout << 'X';
            else
            {
                cout << 'R';
                ++cur;
            }
            ++i;
        }
    }
    else
    {
        while (cur != f)
        {
            if ((cur-1 >= wtc[i].F && cur-1 <= wtc[i].S) || (cur >= wtc[i].F && cur <= wtc[i].S))
                cout << 'X';
            else
            {
                cout << 'L';
                --cur;
            }
            ++i;
        }
    }
}

int main()
{
    speed;
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
    }
}
