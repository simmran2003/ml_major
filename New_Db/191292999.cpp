#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = a; i < b; i++)
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define nl endl
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define popcount(x) __builtin_popcount(x)
typedef long double ld;
#define vi vector<int>
#define ff first
#define sec second
#define coutyes cout<<"YES"<<endl
#define coutno cout<<"NO"<<endl
const int32_t MOD = 1e9 + 7;
const int32_t mod = 998244353;
#define sort_des(arr) sort(arr, arr + n, greater<int>());


int32_t main(){
   ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);cout.tie(NULL);

int n,m,s,f;cin>>n>>m>>s>>f;
map<int,pair<int,int>>mp;
f(i,0,m){
    int p,q,r;cin>>p>>q>>r;
    mp[p]={q,r};
}

int step=1;
if(f>s){//RRRR
int a=s,b=s+1;
while(a!=f){
auto it=mp.find(step);

if(it==mp.end()){
    cout<<'R';
    a++;b++;
}
else{
    int u=mp[step].ff;
    int v=mp[step].sec;
    if((a<=v && a>=u) || (b<=v && b>=u)){
    cout<<'X';
    }
    else{
        cout<<'R';
        a++;b++;
    }
}
// a++;b++;
step++;
}


}
else{//LLLL
int a=s,b=s-1;
while(a!=f){
auto it=mp.find(step);

if(it==mp.end()){
    cout<<'L';
    a--;b--;
}
else{
    int u=mp[step].ff;
    int v=mp[step].sec;
    if((a<=v && a>=u) || (b<=v && b>=u)){
    cout<<'X';
    }
    else{
        cout<<'L';
        a--;b--;
    }
}
// a++;b++;
step++;


}
}
    return 0;
}