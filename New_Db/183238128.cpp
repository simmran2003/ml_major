#include <bits/stdc++.h>
using namespace std;
#define int long long
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define all(a) a.begin(), a.end()
#define pb push_back
#define ii pair <int, int>
#define sd second
#define ft first
#define bit(i) (i & (-i))
#define base 29
#define endl '\n'
#define mod 1000000007ll
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

string yno[2] = { "NO\n", "YES\n" };

const int maxn = 505;

int n, m, f[maxn][maxn];
ii a[maxn], b[maxn];

bool check(ii a, ii b, ii c){
    if(c.sd <= a.sd || b.sd < c.sd) return false;
    return ((a.sd+b.sd)*(a.ft-b.ft) + (b.sd+c.sd)*(b.ft-c.ft) + (c.sd+a.sd)*(c.ft-a.ft)) > 0;
}

void solve(){
    cin>>n>>m;
    foru(i,1,n){
        cin>>a[i].ft>>a[i].sd;
    }
    foru(i,1,m){
        cin>>b[i].ft>>b[i].sd;
    }
    sort(a+1, a+n+1, [](ii a, ii b){return a.sd < b.sd;});
    foru(i,1,n){
        foru(j,i+1,n){
            foru(k,1,m){
                f[i][j] += check(a[i], a[j], b[k]);
            }
        }
    }
    int ans = 0;
    foru(i,1,n){
        foru(j,i+1,n){
            foru(k,j+1,n){
                ans += (f[i][k] == f[i][j] + f[j][k]);
            }
        }
    }
    cout<<ans<<endl;
}

#undef int
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("Test.inp", "r", stdin);
//    freopen("Test.out", "w", stdout);
#endif
    int t = 1;
//    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
