#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pb push_back
#define fo(i,a,b) for (long long i = a; i <b; ++i)
#define all(v) v.begin(), v.end()
#define ff first
#define ss second
#define rev(v) v.rbegin(),v.rend()
#define coutyes cout << "YES" << nl
#define coutno cout << "NO" << nl
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pll pair<ll, ll>
#define nl '\n'
using namespace std;
using ll = long long;
using ld = long double;
 
const int32_t MOD = 1e9 + 7;
 
void solve()
{
    int n,m,s,f;
  cin>>n>>m>>s>>f;
  int arr[m][3];
  vector<char> ans;
  fo(i,0,m)cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
  if(s<f){
      int t=s;int i=1,mc=0;
      while(t!=f){
           if(i!=arr[mc][0]){ans.pb('R');t++;}
           else{
               if(t >=arr[mc][1]-1 && t<=arr[mc][2]) ans.pb('X');
               else {ans.pb('R');t++;}
               mc++;
           }      
        i++;
      }
      for(auto i:ans) cout<<i;
      cout<<nl;
  }
  else{
      int t=s;int i=1,mc=0;
      while(t!=f){
           if(i!=arr[mc][0]){ans.pb('L');t--;}
           else{
               if(t>=arr[mc][1] && t<=arr[mc][2]+1) ans.pb('X');
               else {ans.pb('L');t--;}
               mc++;
           }   
        i++;
      }
    for(auto i:ans) cout<<i;
    cout<<nl;
  }
}
signed main()
{
    IOS;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}