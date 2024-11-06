#include <bits/stdc++.h>
using namespace std;

void setIO(string name = ""){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }

}

bool cmp(const string& x, const string& y) {
    return x+y < y+x;
}

void solve() {
    int n; cin >> n;
    vector<string> s;
    for (int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        s.push_back(tmp);    
    }
    string res = "";
    sort(s.begin(), s.end(), cmp);
    for (auto st: s) {
        res += st;
    }
    cout << res;
}

int main() {
    setIO("");
    int t = 1;
    //cin >> t;
    while (t--) solve();
}