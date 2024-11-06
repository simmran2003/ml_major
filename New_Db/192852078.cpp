#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=1<<20;
int n,m;
long long fpow(long long x,int y) {
	long long res=1;
	while(y>0) {
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int tr[N];
const int inv=fpow(N,mod-2);
const int G=3,invG=fpow(3,mod-2);
struct poly {
	long long f[N];
	poly() {
		memset(f,0,sizeof(f));
	}
	void ntt(int t) {
		for(int i=0; i<N; i++) {
			if(i<tr[i])swap(f[i],f[tr[i]]);
		}
		for(int k=2,l=1; k<=N; k<<=1,l=k>>1) {
			long long w=fpow(t?G:invG,(mod-1)/k);
			for(int i=0; i<N; i+=k) {
				long long wn=1;
				for(int j=i; j<i+l; j++) {
					long long t=wn*f[l+j]%mod;
					f[l+j]=(f[j]-t+mod)%mod;
					f[j]=(f[j]+t)%mod;
					wn=wn*w%mod;
				}
			}
		}
		if(t==0) {
			for(int i=0; i<N; i++) {
				f[i]=f[i]*inv%mod;
			}
		}
	}
	friend poly operator *(poly f,poly g) {
		poly ans;
		f.ntt(1),g.ntt(1);
		for(int i=0; i<N; i++) {
			ans.f[i]=f.f[i]*g.f[i]%mod;
		}
		ans.ntt(0);
		return ans;
	}
} f,g;
int main() {
	for(int i=0; i<N; i++) {
		tr[i]=(tr[i>>1]>>1)|((i&1)?N>>1:0);
	}
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		int x;
		scanf("%d",&x);
		f.f[x]=x;
	}
	g.f[0]=1;
	while(m) {
		if(m&1)g=g*f;
		m>>=1;
		if(m==0)break;
		f=f*f;
	}
	for(int i=0; i<N; i++) {
		if(g.f[i])printf("%d ",i);
	}
	return 0;
}