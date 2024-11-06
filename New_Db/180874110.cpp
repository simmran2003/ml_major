#include<bits/stdc++.h>
using namespace std;
#define int long long
#define name "Untitled1"
const int maxn=501;
int n,m,dp[maxn][maxn]={};
vector<int> f(maxn,0);
vector<pair<int,int>> a(maxn),b(maxn);
inline int area(pair<int,int> a1, pair<int,int> a2, pair<int,int> a3) {
    int s=(a1.second+a2.second)*(a1.first-a2.first)+(a2.second+a3.second)*(a2.first-a3.first)+(a3.second+a1.second)*(a3.first-a1.first);
    return ((s<0) ? (-s) : (s));
}
inline bool in(pair<int,int> point, pair<int,int> a1, pair<int,int> a2, pair<int,int> a3, pair<int,int> a4) {
    return (area(point,a1,a2)+area(point,a2,a3)+area(point,a3,a4)+area(point,a4,a1)==area(a1,a2,a3)+area(a3,a4,a1));
}
inline void solve() {
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        int x,y;
        cin>>x>>y;
        a[i]={x,y};
    }
    for (int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        b[i]={x,y};
    }
    sort(a.begin(),a.begin()+n);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            pair<int,int> a1={a[i].first,-1e9-1},a2={a[j].first,-1e9-1};
            for (int k=0; k<m; k++) {
               dp[i][j]+=in(b[k],a[i],a[j],a2,a1);
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            f[i]+=(b[j].first==a[i].first && b[j].second<=a[i].second);
        }
    }
    int res=0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
               pair<int,int> a1={a[i].first,-1e9-1},a2={a[j].first,-1e9-1},a3={a[k].first,-1e9-1};
               int d;
               if (area(a[i],a[j],a2)+area(a2,a1,a[i])+area(a[j],a[k],a3)+area(a3,a2,a[j])>=area(a[i],a[k],a3)+area(a3,a1,a[i])) {
                  d=dp[i][j]+dp[j][k]-dp[i][k]-f[j];
               }
               else {
                  d=dp[i][k]-dp[i][j]-dp[j][k]+f[j];
               }
               res+=(d==0);
            }
        }
    }
    cout<<res;
}
signed main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   if (fopen(name".INP", "r")) {
      freopen(name".INP","r",stdin);
      //freopen(name".OUT", "w", stdout);
   }
   int t=1;
   if (0) cin>>t;
   while (t--) solve();
}

