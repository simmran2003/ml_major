#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll base = 37;//进制
const ll mod = 1e9+7;//质数
const int inf = 1e9+5;
const int maxn = 1e5+5;
const ll linf = 1e18+5ll;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n,p;
    cin>>n>>p;
    vector<string>str(n);
    for(auto &x : str)
        cin>>x;
    reverse(str.begin(),str.end());
    ll sum = 0;
    int cnt = 0;
    for(auto x : str)
    {
        if(x=="halfplus")
        {
            sum = sum*2+1;
            cnt++;
        }
        else
        {
            sum = sum*2;
        }
    }
    ll ans = sum*p -  p*cnt/2;
    cout<<ans<<endl;
    system("pause");
}
/*

*/