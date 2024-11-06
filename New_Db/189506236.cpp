#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1<<20,mod=1e9+7,iv2=(mod+1)/2,iv6=(mod+1)/6;
int op[N];
void solve(){
    ll n,p;cin>>n>>p;
    ll nw=0;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        op[i]=s.size()==4;
    }
    for(int i=n;i>=1;i--)if(op[i])nw*=2;else nw=nw*2+1;
    ll rs=0;
    for(int i=1;i<=n;i++){
        if(op[i])rs+=nw/2*p;
        else rs+=nw/2*p+p/2;
        nw/=2;
    }
    cout<<rs<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    int T=1;
    //cin>>T;
    while(T--)solve();
}