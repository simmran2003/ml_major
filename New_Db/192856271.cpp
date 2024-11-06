#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i, a, b) for(int i = (a); i <= (b); i++)
#define cl(i, n) i.clear(),i.resize(n);
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int inf = 1e9;
//#define cerr if(false)cerr
//#define freopen if(false)freopen
#define watch(x) cerr  << (#x) << ' '<<'i'<<'s'<<' ' << x << endl
void pofe(int number, int bitnum) {
    string s; f(i, 0, bitnum) {s += char(number & 1) + '0'; number >>= 1; } 
    reverse(s.begin(), s.end()); cerr << s << endl; 
    return;
}
void cmax(int &x, int y) {if(x < y) x = y;}
void cmin(int &x, int y) {if(x > y) x = y;}
//调不出来给我对拍！
int n, k; 
int dp[1000010], a[1010];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen();
    //freopen();
    //time_t start = clock();
    //think twice,code once.
    //think once,debug forever.
    cin >> n >> k; f(i, 1, n) cin >> a[i];
    int mn = inf, mx = 0; f(i, 1, n) {cmin(mn, a[i]); cmax(mx, a[i]); }
    f(i, 1, n) a[i] -= mn; 
    memset(dp, 0x3f, sizeof(dp)); dp[0] = 0;// f(i, 1, n) cerr << a[i] << endl;
    f(i, 1, n) {
        f(j, a[i], k * mx) {
            cmin(dp[j], dp[j - a[i]] + 1);
        }
    }
 //   f(i, 0, k * mx) cerr << dp[i] << " ";
 //   cerr << endl;
    f(i, 0, k * mx) if(dp[i] <= k) cout << i + mn * k << " "; 
    //time_t finish = clock();
    //cout << "time used:" << (finish-start) * 1.0 / CLOCKS_PER_SEC <<"s"<< endl;
    return 0;
}
/*
2023/x/xx
start thinking at h:mm


start coding at h:mm
finish debugging at h:mm
*/
 	       	 	 					     		  	 	