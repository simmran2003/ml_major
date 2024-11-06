#include<iostream>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cmath>
#include<deque>
#include<iomanip>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<unordered_map>
#include<tuple>
#include<vector>
#include<random>
#include<string>
#include<complex>

//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#define int int_fast64_t
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& _ : a) {cout << _ << " ";} cout << '\n';
#define input(a) for (auto& _ : a) cin >> _;

template<typename T>
bool assign_min(T &a, T b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool assign_max(T &a, T b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

void pref_calc(std::vector<int> &a, std::vector<int> &b) {
    for (int i = 0; i<(int)a.size(); ++i) {
        b[i] = (i == 0 ? a[i] : b[i-1]+a[i]);
    }
}

using namespace std;
mt19937_64 rnd(time(nullptr));
const int mod = 1e9+7;

int cnt(string s1, string s2, string s3) {
    int n = (int)s1.size();
    if (n == 0) {
        return 1;
    }
    vector<string> s(n);
    for (int i = 0; i<n; ++i) {
        s[i] = s1.substr(i, 1)+s2.substr(i, 1)+s3.substr(i, 1);
    }
    vector<vector<int>> dp(n, vector<int> (1 << 4));
    if (s[0] == "XXX") {
        dp[0][7] = 1;
    }
    else if (s[0] == "XX.") {
        dp[0][6] = 1;
    }
    else if (s[0] == "X.X") {
        dp[0][5] = 1;
    }
    else if (s[0] == ".XX") {
        dp[0][3] = 1;
    }
    else if (s[0] == "X..") {
        dp[0][7] = 1;
        dp[0][4] = 1;
    }
    else if (s[0] == ".X.") {
        dp[0][2] = 1;
    }
    else if (s[0] == "..X") {
        dp[0][7] = 1;
        dp[0][1] = 1;
    }
    else {
        dp[0][3] = 1;
        dp[0][6] = 1;
        dp[0][0] = 1;
    }
    for (int i = 1; i<n; ++i) {
        if (s[i] == "XXX") {
            dp[i][7] = dp[i-1][7];
        }
        else if (s[i] == "XX.") {
            dp[i][7] = dp[i-1][6];
            dp[i][6] = dp[i-1][7];
        }
        else if (s[i] == "X.X") {
            dp[i][7] = dp[i-1][5];
            dp[i][5] = dp[i-1][7];
        }
        else if (s[i] == ".XX") {
            dp[i][7] = dp[i-1][3];
            dp[i][3] = dp[i-1][7];
        }
        else if (s[i] == "X..") {
            dp[i][7] = (dp[i-1][7]+dp[i-1][4])%mod;
            dp[i][6] = dp[i-1][5];
            dp[i][5] = dp[i-1][6];
            dp[i][4] = dp[i-1][7];
        }
        else if (s[i] == ".X.") {
            dp[i][7] = dp[i-1][2];
            dp[i][6] = dp[i-1][3];
            dp[i][3] = dp[i-1][6];
            dp[i][2] = dp[i-1][7];
        }
        else if (s[i] == "..X") {
            dp[i][7] = (dp[i-1][7]+dp[i-1][1])%mod;
            dp[i][5] = dp[i-1][3];
            dp[i][3] = dp[i-1][5];
            dp[i][1] = dp[i-1][7];
        }
        else {
            dp[i][0] = dp[i-1][7];
            dp[i][1] = dp[i-1][6];
            dp[i][2] = dp[i-1][5];
            dp[i][3] = (dp[i-1][4]+dp[i-1][7])%mod;
            dp[i][4] = dp[i-1][3];
            dp[i][5] = dp[i-1][2];
            dp[i][6] = (dp[i-1][1]+dp[i-1][7])%mod;
            dp[i][7] = (dp[i-1][0]+dp[i-1][3]+dp[i-1][6])%mod;
        }
    }
    return dp[n-1][7];
}

void solve() {
    int n;
    cin >> n;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    bool fl = true;
    for (int i = 0; i<n; ++i) {
        if (s1[i] == 'O' || s2[i] == 'O' || s3[i] == 'O') {
            if (s1[i] == 'O') {
                s1[i] = 'X';
            }
            else if (s3[i] == 'O') {
                s3[i] = 'X';
            }
            else {
                if (i == 0) {
                    s2[i] = s2[i+1] = s2[i+2] = 'X';
                }
                else if (i == n-1) {
                    s2[i] = s2[i-1] = s2[i-2] = 'X';
                }
                else {
                    if (s1[i-1] == 'X' || s2[i-1] == 'X' || s3[i-1] == 'X' || s1[i] == 'X' || s3[i] == 'X' || s1[i+1] == 'X' || s2[i+1] == 'X' || s3[i+1] == 'X') {
                        s2[i] = 'X';
                    }
                    else {
                        fl = false;
                    }
                }
            }
            break;
        }
    }
    if (fl) {
        cout << cnt(s1, s2, s3) << '\n';
        return;
    }
    int ind = 0;
    while (s2[ind] != 'O') {
        ind++;
    }
    s2[ind] = 'X';
    int res1 = cnt(s1, s2, s3);
    int res2 = cnt(s1.substr(0, ind-1), s2.substr(0, ind-1), s3.substr(0, ind-1));
    int res3 = cnt(s1.substr(ind+2, n-(ind+2)), s2.substr(ind+2, n-(ind+2)), s3.substr(ind+2, n-(ind+2)));
    cout << (res1+mod-(2*res2*res3)%mod)%mod << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}