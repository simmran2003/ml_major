#include <bits/stdc++.h>
typedef long long ll;
const int N=2503,mod=998244353;
using namespace std;
int a[N][N],f[N];
vector<pair<int,int>>mp[N];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int mx[N];
void dfs(int x,int fa,int rt){
    if(a[rt][x]>mx[x]){
        cout<<"NOT MAGIC\n";
        exit(0);
    }
    for(auto[i,val]:mp[x])if(i^fa)mx[i]=max(mx[x],val),dfs(i,x,rt);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
    for(int i=1;i<=n;i++)if(a[i][i])return cout<<"NOT MAGIC\n",0;
    vector<tuple<int,int,int>>eg;
    for(int i=1;i<=n;i++)for(int j=1+i;j<=n;j++){
        if(a[i][j]^a[j][i])return cout<<"NOT MAGIC\n",0;
        eg.emplace_back(a[i][j],i,j);
    }
    std::sort(eg.begin(), eg.end());
    iota(f,f+n+1,0);
    for(auto[val,x,y]:eg){
        int fx=find(x),fy=find(y);
        if(fx!=fy)f[fx]=fy,mp[x].emplace_back(y,val),mp[y].emplace_back(x,val);
    }
    for(int i=1;i<=n;i++)dfs(i,0,i),memset(mx,0,sizeof mx);
    cout<<"MAGIC\n";
}