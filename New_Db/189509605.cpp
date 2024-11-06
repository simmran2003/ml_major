#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1<<20,mod=1e9+7;
int a[N],cnt[N],sz[N];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];if(a[i]<=m)cnt[a[i]]++;}
    for(int i=1;i<=m;i++)for(int j=i;j<=m;j+=i)sz[j]+=cnt[i];
    int mx=*max_element(sz+1,sz+m+1);
    if(mx==0)return cout<<1<<' '<<0<<'\n',void();
    for(int i=1;i<=m;i++)if(sz[i]==mx){
        cout<<i<<' '<<mx<<'\n';
        for(int j=1;j<=n;j++)if(i%a[j]==0&&i!=0)cout<<j<<' ';cout<<'\n';
        return;
    }
}

int main(){
    ios::sync_with_stdio(0);
    int T=1;
    //cin>>T;
    while(T--)solve();
}