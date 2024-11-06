#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
using ull=unsigned long long;
const int N=3e3+10;
const int mod=998244353;
#define int long long
int qmi(int a,int b){
    int res=1;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)res=res*a%mod;
    return res;
}
namespace Polynomial{
    #define ADD(a,b) ((a)+=(b),(a)>=P?(a)-=P:0)
    #define SUB(a,b) ((a)-=(b),(a)<0?(a)+=P:0)
    #define MUL(a,b) ((a)*(b)%P)
    using Poly=vector<int>;
    constexpr int P(469762049),G(3);
    int qpow(int a,int n=P-2,int x=1){
        for(;n;n>>=1,a=MUL(a,a))
            if(n&1)x=MUL(x,a);
        return x;
    }
    template<int n>
    array<int,n> INIT(){
        array<int,n> w;
        for(int i=n>>1,x=qpow(G,(P-1)/n);i;i>>=1,x=MUL(x,x)){
            w[i]=1;
            for(int j=1;j<i;j++){
                w[i+j]=MUL(w[i+j-1],x);
            }
        }
        return w;
    }
    auto w=INIT<1<<21>();
    void DFT(Poly &f){
        int n=f.size();
        for(int k=n>>1;k;k>>=1){
            for(int i=0;i<n;i+=k<<1){
                for(int j=0;j<k;j++){
                    int y=f[i+j+k];
                    f[i+j+k]=MUL(f[i+j]-y+P,w[k+j]);
                    ADD(f[i+j],y);
                }
            }
        }
    }
    void IDFT(Poly &f){
        int n=f.size();
        for(int k=1;k<n;k<<=1){
            for(int i=0;i<n;i+=k<<1){
                for(int j=0;j<k;j++){
                    int y=MUL(f[i+j+k],w[k+j]);
                    f[i+j+k]=(f[i+j]-y+P)%P;
                    ADD(f[i+j],y);
                }
            }
        }
        for(int i=0,inv=P-(P-1)/n;i<n;i++){
            f[i]=MUL(f[i],inv);
        }
        reverse(f.begin()+1,f.end());
    }
    void DOT(Poly &f,Poly &g){
        for(int i=0;i<f.size();i++){
            f[i]=MUL(f[i],g[i]);
        }
    }
    Poly operator *(Poly f,Poly g){
        int n=f.size()+g.size()-1,k=__lg(n-1)+1,s=1<<k;
        f.resize(s);
        g.resize(s);
        DFT(f),DFT(g),DOT(f,g),IDFT(f);
        return f.resize(n),f;
    }
    Poly polyInv(Poly f){
        if(f.size()==1)return {qpow(f[0])};
        int n=f.size(),k=__lg(2*n-1)+1,s=1<<k;
        Poly g=polyInv(Poly(f.begin(),f.begin()+(n+1>>1)));
        g.resize(s);
        f.resize(s);
        DFT(f),DFT(g);
        for(int i=0;i<s;i++){
            f[i]=MUL(g[i],P-MUL(f[i],g[i])+2);
        }
        IDFT(f);
        return f.resize(n),f;
    }
    Poly deriv(Poly f){
        for(int i=1;i<f.size();i++){
            f[i-1]=MUL(i,f[i]);
        }
        f.pop_back();
        return f;
    }
    Poly integ(Poly &f,int c=0){
        int n=f.size();
        Poly g(n+1);
        g[0]=c;
        for(int i=0;i<n;i++){
            g[i+1]=MUL(f[i],qpow(i+1));
        }
        return g;
    }
    Poly polyLn(Poly f){
        int n=f.size();
        //assert(f[0]==1);
        f=polyInv(f)*deriv(f);
        f.resize(n-1);
        return integ(f);
    }
    Poly polyExp(Poly f){
        if(f.size()==1)return {1};
        //assert(f[0]==0);
        int n=f.size();
        Poly g=polyExp(Poly(f.begin(),f.begin()+(n+1>>1)));
        g.resize(n);
        Poly h=polyLn(g);
        for(int i=0;i<n;i++){
            SUB(f[i],h[i]);
        }
        ADD(f[0],1);
        return f=f*g,f.resize(n),f;
    }
}
using namespace Polynomial;
void solve(){
    int n,k;cin>>n>>k;
    Poly f(1001),g(1,1);
    rep(i,1,n){
        int x;cin>>x;
        f[x]=1;
    }
    while(k){
        if(k&1)g=f*g;
        f=f*f,k>>=1;
    }
    rep(i,1,g.size()-1)if(g[i])cout<<i<<" ";
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc = 1;
    //cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve();
    }
}