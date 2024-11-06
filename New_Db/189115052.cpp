#include <bits/stdc++.h>
#define IOS   ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define xs(a) cout<<setiosflags(ios::fixed)<<setprecision(a);
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define mem(a,b) memset(a,b,sizeof(a));
using namespace std;
#define ull unsigned long long
#define ll int
#define endl '\n'
typedef pair<ll,ll> pll;
const int N=3e3+5;
const int mod=1e9+7;
/*-----------------------------------------------------------------------------------------------*/

ll a[N][N];

bitset<2600>bt[2600];
signed main(){IOS
    ll n;cin>>n;
    FOR(i,1,n)FOR(j,1,n)cin>>a[i][j];
    FOR(i,1,n){
        FOR(j,1,n){
            if(i==j&&a[i][j]){cout<<"NOT MAGIC"<<endl;return 0;}
            else if(a[i][j]!=a[j][i]){cout<<"NOT MAGIC"<<endl;return 0;}
        }
    }
    vector<array<ll,3>>vec;
    FOR(i,1,n){
        FOR(j,i+1,n)vec.push_back({a[i][j],i,j});
    }
    sort(vec.begin(),vec.end(),[&](array<ll,3>l,array<ll,3>r){
        return l[0]>r[0];
    });
    ll m=vec.size();
    for(int i=0;i<m;){
        ll j=i;
        for(j;j<m&&vec[j][0]==vec[i][0];j++){
            ll x=vec[j][1],y=vec[j][2];
            bt[x][y]=1;bt[y][x]=1;
        }
        for(i;i<j;i++){
            ll x=vec[i][1],y=vec[i][2];
            if((bt[x]|bt[y]).count()!=n){
                cout<<"NOT MAGIC"<<endl;return 0;
            }
        }
    }
    cout<<"MAGIC"<<endl;
    

    return 0;
}