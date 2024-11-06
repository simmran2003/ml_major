#include<bits/stdc++.h>
using namespace std;

bool cmp(string& a, string& b)
{
    return a + b < b + a; // ex: a=xxaaa, b=xxaa; => a+b=xxaaaxxaa, b+a=xxaaxxaaa; a+b < b+a; so they will be sorted in this way. 
}

void solve()
{
    int n;  cin>>n;

    vector<string> v(n);
    for(auto& x : v) cin>>x;

    sort(v.begin(), v.end(), cmp);

    string ans;
    for(auto x : v)
    {
        ans += x;
    }

    cout<< ans <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tests = 1;
    // cin >> tests;

    while(tests--)
    {
        solve();
    }

    return 0;
}