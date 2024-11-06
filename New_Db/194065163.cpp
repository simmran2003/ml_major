// https://codeforces.com/problemset/problem/342/A

#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
const int inf = INT_MAX;
const int ninf = INT_MIN;

template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v){cout<<"[ ";for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}return cout<<"]";}
template<typename T> void sort(vector<T>& v){sort(v.begin(),v.end());}
template<typename T> void rsort(vector<T>& v){sort(v.rbegin(),v.rend());}
template<typename T1,typename T2> void seta(T1& a,int n,T2 v){for(int i=0;i<n;i++)a[i]=v;}

vector<int> c(7);
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        if (in == 5 || in == 7) {
            cout << -1 << nl;
            return;
        }
        c[in]++;
    }

    vector<string> res;
    while (c[6] && c[3] && c[1]) {
        res.push_back("1 3 6");
        c[6]--;
        c[3]--;
        c[1]--;
    }

    while (c[6] && c[2] && c[1]) {
        res.push_back("1 2 6");
        c[6]--;
        c[2]--;
        c[1]--;
    }

    while (c[4] && c[2] && c[1]) {
        res.push_back("1 2 4");
        c[4]--;
        c[2]--;
        c[1]--;
    }

    for (int i:c) {
        if (i > 0) {
            cout << -1 << nl;
            return;
        }
    }

    for (string s:res) {
        cout << s << nl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
