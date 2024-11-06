//SHREE GANESHAYA NAMAH
//OM NAMAHA SHIVAY
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);
using namespace std;
const int N=(int)1e9+7;
// etf in sqrt(n) using prime factorisation
// ll int phi(ll int n){
//     ll int res=n;
//     for(ll int i=2;i*i<=n;i++){
//         if(n%i==0){
//             res/=i;
//             res*=(i-1);
//         }
//         while(n%i==0){
//             n/=i;
//         }
//     }
//     if(n>1){
//         res/=n;
//         res*=(n-1);
//     }
//     return res;
// }
// etf in nlog(logn) using sieve algo
// ll int p[1000001];
// void phif(ll int n){
//     for(ll int i=1;i<=n;i++){
//         p[i]=i;
//     }
//     for(ll int i=2;i<=n;i++){
//         if(p[i]==i){
//             for(ll int j=i;j<=n;j+=i){
//                 p[j]/=i;
//                 p[j]*=(i-1);
//             }
//         }
//     }
// }
// ll int bin(ll int a,ll int b){
//     ll int ans=1;
//     while(b>0){
//         if(b&1){
//             ans=(ans*a)%N;
//         }
//         a=(a*a)%N;
//         b>>=1;
//     }
//     return ans%N;
// }
int main(){
    fastio()
    // phif(1000001);
    //binary search sample code on monotonic functions 
    ll int r,h;
    cin>>r>>h;
    ll int ans=(h+(r/2))/r;
    ll int ex=h+r-(ans*r);
    double val=sqrt(0.75);
    if(ex>=val*r){
        cout<<2*ans+1;
    }
    else{
        cout<<2*ans;
    }
    return 0;
}
