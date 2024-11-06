#include <bits/stdc++.h>
//#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
#define ss second
#define ff first
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define vl vector<ll>
#define pll pair<ll,ll>
#define vll vector<pll>
#define vd vector<db>
#define pdd  pair<db,db>
#define vdd  vector<pdd>
#define mll map <ll,ll>
#define sl set <ll>
#define sll set <pll>
#define f(i,j,k,l) for(ll i=j;i<k;i+=l)
#define fj(j,m) for(auto j=m.begin();j!=m.end();j++)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
const db pi=3.14159265359;
const int MOD = 1e9 + 7;
const db EPS = 0.000000001; // 1 e -9
const ll inf = (ll)1e18;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
bool pre[100001];
set <long long> s;
typedef long long ll;
void premier(ll x){
    for (long long i=2;i<=x;i++){
        if(pre[i]){
            s.insert(i);
            for (ll j=i*i;j<=x;j+=i){
                pre[j]=0;
            }
        }
    }
}
/*int main()
{
    memset(pre,1,sizeof(pre));
    pre[1]=0;
    premier(1000001);
return 0;
}
*/
//std::cout << std::setprecision(7) << std::fixed;
void prem(ll x){
    for (ll i=1;i*i<=x;i++){
        if(x%i==0){
            s.insert(i);
            s.insert(x/i);
        }
    }
}
bool premi(ll k)
{
    bool l=1;
     for (auto j=s.begin();j!=s.end();j++)
     {
         if ((*j)*(*j)>k) break;
         if (k%*j==0) {l=0;break;}
     }
     return l;
}
ll premie(ll k,ll j)
{
    ll n=0;
    while (k%j==0)
    {
        k/=j;
        n+=1;
    }
    return n;
}

int run_case()
{
    ll  n,r,p,h,u,k,q,d,i,x,y,z;
    db d1;
    cin >> r >> h;
    d=(2*h+r)/(2*r);//cout << (((float)sqrt(3))-1)*((float)r/2) << endl;
    d1=h-((float)r/2)-(d-1)*r;//cout << d1 << endl;
    if ((((float)sqrt(3))-1)*((float)r/2)<d1) cout << (d)*2+1 << endl;
    else cout << ((ll)d)*2 << endl;
    /*char t;
    cin>>k>>n;
    x=0;y=1000000;z=0;p=10000000;
    char a[k][n];
    f(i,0,k,1)f(j,0,n,1)
    {
        cin>> t ;
        a[i][j]=t;
        if (t=='B') {x=max(x,i);y=min(y,i);z=max(z,j);p=min(p,j);}
    }
    if ((x+y)%2 && (z+p%2))
    {
        if (a[x][p]=='W') p++;
        else if (a[y][z]=='W') y++;
        else if (a[y][p]=='W') {p++;y++;}
    }
    cout << (x+y)/2+1 << " " << (z+p)/2+1 << endl;*/
return 0;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1; //cin>>t;
    while(t--){
        run_case();
    }
    return 0;
}
