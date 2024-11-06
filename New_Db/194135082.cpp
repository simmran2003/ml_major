#include <bits/stdc++.h>  // Hello There :)

#define Be_Fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
//					..........Maryam Tarek..........
using namespace std;

bool sortLogic (string &p1,string &p2)
{
//    if (p1.size()==p2.size()) return (p1>p2);
//    return (p1.size()>p2.size());
    return (p1+p2<p2+p1);
}

void solve()
{
    int n;cin>>n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) cin>>v[i];
    sort(v.begin(),v.end(), sortLogic);
    for (int i = 0; i < n; ++i) cout<<v[i];
}

int main() {
    Be_Fast;
    solve();
}