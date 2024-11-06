#include"bits/stdc++.h"
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a, fa, sum=0;
    cin>>a;
    fa = a;
    for (ll i=2; i<a; i++) {
      fa=a;
      while (fa>0) {
        sum+=fa%i;
        fa/=i;
      }
    }
    cout<<sum/(__gcd(sum, a-2))<<"/"<<(a-2)/(__gcd(sum, a-2));
}
