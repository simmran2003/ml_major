/*
    created by Allwinn3r at 18:05 02.02.2023
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    int n , p;
    cin >> n >> p;

    vector <bool> half(n , false);

    for(int i = 0 ; i < n ; ++i){
        string s;
        cin >> s;

        if(s == "halfplus"){
            half[i] = true;
        }
    }

    ll integ = 0, floatable = 0;
    for(int i = n - 1 ; i >= 0 ; --i){
        integ *= 2;
        if(half[i]){
            ++integ;
            ++floatable;
        }
    }

    cout << integ * p - floatable * p / 2 << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }
}
