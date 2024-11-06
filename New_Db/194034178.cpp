#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foru(i, l, r) for(int i = l; i <= r; i++)
#define ford(i, r, l) for(int i = r; i >= l; i--)
 
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;
 
const int N = 1e6 + 5;
 
const int oo = 1e9 + 7, mod = 1e9 + 7;
 
int n, m; string s[N];
vector<int> arr;

void read() {
	
}

void init() {
	
}

bool cmp(string a, string b) {
	return (a+b)<(b+a);
}

void process() {
	cin >> n;
	foru(i,1,n) cin >> s[i];
	sort(s+1, s+1+n, cmp);
	foru(i,1,n) cout << s[i];
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	//freopen(".inp", "r", stdin);
	//freopen(".out", "w", stdout);
	read();
	init();
	process();
	return 0;
}
