/**
  * > File Name:     AC.cpp
  * > Author:        Ayanamijia
  * > Created Time:  2023-02-09 10:00:23
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    string s;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    cin >> s;
    ll B = 0;
    for (int i = 0; i < n; i ++ ) {
        if (s[i] == 'B') B += a[i];
    }
    ll ans = B, cnt = B;
    for (int i = 0; i < n; i ++ ) {
        if (s[i] == 'A') B += a[i];
        else B -= a[i];
        ans = max(ans, B);
    }
    B = cnt;
    for (int i = n - 1; i >= 0; i -- ) {
        if (s[i] == 'A') B += a[i];
        else B -= a[i];
        ans = max(ans, B);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t -- ){
        solve();
    }
    return 0;
}
 	     		 	         	 	 	  	