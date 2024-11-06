#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<int, int> vpi;
typedef map<int, int> mi;
typedef set<int> si;

#define xx '\n'
#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
#define sc(x) int x; cin >> x;
#define all(x) x.begin(), x.end()

const double E = 1e-8;

bool cmp(const string& a, const string& b) {
    return a + b < b + a;
}

int main() {
    fastio();
    sc(tt);
    int k = tt;
    vector<string> v;
    while (tt--) {
        string x;
        cin >> x;
        v.push_back(x);
    }

    sort(all(v), cmp);

    string ans = accumulate(v.begin(), v.end(), string());

    cout << ans;
}