#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> poly;
const int mod=998244353;
const int G=3;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

void ntt(poly &p,bool inv){
    int n=p.size();
    static vector<int> r;
    static int d;
    if(d!=n){
        d=n;
        if(r.size()<d)r.resize(d);
        for(int i=0;i<n;i++){
            r[i]=r[i>>1]>>1;
            if(i&1)r[i]|=n>>1;
        }
    }
    for(int i=0;i<n;i++){
        if(r[i]>i)swap(p[i],p[r[i]]);
    }
    for(int i=2;i<=n;i*=2){
        ll wn=qpow(G,(mod-1)/i),w=1;
        int u,t;
        if(inv)wn=qpow(wn,mod-2);
        for(int j=0;j<i/2;j++){
            for(int k=j;k<n;k+=i){
                u=p[k];
                t=w*p[i/2+k]%mod;
                p[k]=u+t>=mod?u+t-mod:u+t;
                p[i/2+k]=u-t<0?u-t+mod:u-t;
            }
            w=w*wn%mod;
        }
    }
    if(inv){
        int in=qpow(n,mod-2);
        for(int &x:p)x=(ll)x*in%mod;
    }
}

poly naive_convolution(const poly &a,const poly &b){
    poly c(a.size()+b.size()-1);
    if(a.size()>b.size()){
        for(int i=0;i<a.size();i++)for(int j=0;j<b.size();j++)c[i+j]=(c[i+j]+(ll)a[i]*b[j])%mod;
    }else{
        for(int j=0;j<b.size();j++)for(int i=0;i<a.size();i++)c[i+j]=(c[i+j]+(ll)a[i]*b[j])%mod;
    }
    return c;
}

poly ntt_convolution(poly a,poly b){
    int n=1,m=a.size()+b.size()-1;
    while(n<m)n*=2;
    a.resize(n);
    b.resize(n);
    ntt(a,0);
    ntt(b,0);
    for(int i=0;i<n;i++)a[i]=(ll)a[i]*b[i]%mod;
    ntt(a,1);
    a.resize(m);
    return a;
}

poly convolution(const poly &a,const poly &b){
    if(a.empty()||b.empty())return poly();
    if(min(a.size(),b.size())<=60)return naive_convolution(a,b);
    return ntt_convolution(a,b);
}

poly qpow(poly a,int n){
    poly r(1,1);
    while(n){
        if(n&1){
            r=convolution(r,a);
            for(int &x:r)x=!!x;
        }
        a=convolution(a,a);
        for(int &x:a)x=!!x;
        n>>=1;
    }
    return r;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    poly a(1001);
    while(n--){
        int b;
        cin>>b;
        a[b]=1;
    }
    while(!a.back())a.pop_back();
    a=qpow(a,k);
    for(int i=0;i<a.size();i++)if(a[i])cout<<i<<' ';
    cout<<'\n';

    return 0;
}

 			 	   	 	 	 	 	  		   	   		