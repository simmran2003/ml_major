#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <set>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <random>
#include <complex>
#include <bitset>
#include <fstream>
#include <list>
#include <numeric>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline void boostIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
}

bool isPrime(int x) {
	if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
	for (int i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1;
}

typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;;
typedef pair<int, int> pii;

#define fori(n) for(int i = 0; i < (n); ++i)
#define forj(n) for(int j = 0; j < (n); ++j)
#define fork(n) for(int k = 0; k < (n); ++k)
#define forx(n) for(int x = 0; x < (n); ++x)

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << x << endl;
#define debug_p(x) cerr << #x << " " << x.ff << " " << x.ss << endl;
#define debug_v(x) cerr << #x << " "; for (auto ii : x) cout << ii << " "; cout << endl;
#define debug_vp(x) cerr << #x << " "; for (auto ii : x) cout << '[' << ii.ff << " " << ii.ss << ']'; cout << endl;
#define mp make_pair
#define rand kjsdflsdfsdlsjdlkfsdjflsjdfl 
#define prev sdjfsldfkjsdlkfjsldkfjlsdkjf
#define next oiasjdoiasjdasljdalsjdlaksjasd
#define time zsdfsijfsldfj83fsdfsdfsdfsdfsd
#define y1   ujqwoejqowiejqowiejqowiejqowij

#define Return cerr<<endl<<"RUNTIME: "<<1.0*clock()/CLOCKS_PER_SEC << " s" <<endl; return 0;

#define PI 3.141592653589793238462643383279502884L


ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }


bool BREAKTIME(ld v) {
	return 1.0 * clock() >= v * CLOCKS_PER_SEC;
}

#define OR(a, b)  ((a) | (b))
#define AND(a, b) ((a) & (b))
#define XOR(a, b) ((a) ^ (b))
#define BIT(a) (1ll << (a))

ll COUNT(ll n) {
	ll count = 0;
	while (n) {
		count += n & 1ll;
		n >>= 1ll;
	}
	return count;
}


///////////////////////
#define int long long
const ll inf = 3e18 + 5;
//const int inf = 1e9 + 5;
ll mod = 1e9 + 7;
#define endl "\n"
//////////////////////

int m, n;
vector<vector<char>> A;

int f() {
	int ans = 0;
	vector<int> dp(BIT(n));
	dp[7] = 1; //everything is black

	for (int j = 1; j <= m; ++j) {
		vector<int> DP(BIT(n));
		for (int prev = 0; prev < BIT(n); ++prev) {
			if (prev == 7) {
				int kek = 1;
			}
			for (int cur = 0; cur < BIT(n); ++cur) {
				vector<int> b(3);
				fori(3) {
					if (AND(BIT(i), prev) != 0) b[i] = 1;
				}

				vector<int>a(3);
				fori(3) {
					if (AND(BIT(i), cur) != 0) a[i] = 1;
				}

				bool valid = 1;
				fori(3) {
					if (a[i] == 1 && A[i + 1][j] != '.') valid = 0;
					if (b[i] == 1 && a[i] == 1) valid = 0;

					if (b[i] == 0 && a[i] == 1) b[i] = 1;
				}

				int combo = 0;
				fori(3) {
					if (b[i] == 0) {
						++combo;
					}
					else {
						if (combo % 2 != 0) {
							valid = 0;
						}
						combo = 0;
					}
				}
				if (combo % 2 != 0) {
					valid = 0;
				}
				combo = 0;

				if (valid == 0) continue;

				int mask = 0;
				fori(3) {
					if (a[i] == 1 || A[i + 1][j] != '.') {
						mask += BIT(i);
					}
				}
				DP[mask] += dp[prev];
				DP[mask] %= mod;
			}


		}
		swap(dp, DP);
	}

	ans = dp[7] + dp[1] + dp[4];
	ans %= mod;
	return ans;
}
void solve() {
	cin >> m;
	n = 3;

	int I, J;
	A.assign(n + 2, vector<char>(m + 2, 'X'));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> A[i][j];
			if (A[i][j] == 'O') {
				I = i;
				J = j;
			}
		}
	}


	int ans = f();

	vector<int> XA = { -1, -1, 0, 1, 1, 1, 0, -1};
	vector<int> YA = { 0, 1, 1 , 1, 0, -1, -1, -1 };

	vector<pair<int, int>> CORD;
	vector<char> C;
	fork(8) {
		int x = I + XA[k];
		int y = J + YA[k];

		C.push_back(A[x][y]);
		A[x][y] = 'X';
		CORD.push_back(mp(x, y));

	}

	vector<pair<int, int>> Z = { mp(0,1), mp(0, 7), mp(1,2), mp(2, 3),  mp(3,4), mp(4, 5) ,mp(5,6), mp(6, 7) };


	for (int MASK = 0; MASK < BIT(8); ++MASK) {
		vector<char> Q = C;
		bool valid = 1;
		for (int w = 0; w < 8; ++w) {
			if (AND(BIT(w), MASK) != 0) {
				for (auto u : { Z[w].ff, Z[w].ss }) {
					if (Q[u] == 'X') {
						valid = 0;
					}
					else {
						Q[u] = 'X';
					}
				}
			}
		}
		if (Q[0] != 'X' || Q[2] != 'X' || Q[4] != 'X' || Q[6] != 'X') valid = 0;

		if (valid == 0) continue;

		fori(8) {
			swap(A[CORD[i].ff][CORD[i].ss], Q[i]);
		}
		//debug(f());
		ans -= f();
		ans += mod;
		ans %= mod;

		fori(8) {
			swap(A[CORD[i].ff][CORD[i].ss], Q[i]);
		}
	}

	cout << ans << endl;

}


int32_t main() {
	boostIO();
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int TT = 1; //cin >> TT;
	while (TT--) {
		solve();
	}
}