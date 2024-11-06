#include <bits/stdc++.h>

using namespace std;
#define int long long
//#define endl "\n"
bool comp(string &s1,string &s2){
    return s1+s2<s2+s1;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<string> k(n);
    int ma = 0;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    sort(k.begin(), k.end(),comp);
    for (int i = 0; i < n; i++) {
        cout<<k[i];
    }

}
