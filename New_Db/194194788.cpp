#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
//#define endl '\n'
const int N=200009;
const int INF=0x3f3f3f3f;
const int mod=998244353;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48); ch=getchar();}
	return s*=f;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+48);
}
inline void print(int x){
	if(x<0){putchar('-'); x=-x;}
	write(x);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> T rnd(T l,T r){return uniform_int_distribution<T>(l,r)(rng);}
inline void file(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
int n,m,B,b[N],k[N],f[N],nxt[N];
inline void update(int id){
	int l=(b[id]-1)*B+1;
	int r=min(b[id]*B,n);
	for(int i=id;i>=l;i--){
		int pos=i+k[i];
		if(pos>r){
			f[i]=1;
			nxt[i]=pos;
		} 
		else{
			f[i]=f[pos]+1;
			nxt[i]=nxt[pos];
		}
	}
}
signed main(){
	n=read(); m=read(); B=sqrt(n);
	for(int i=1;i<=n;i++)k[i]=read(); 
	for(int i=1;i<=n;i++)b[i]=(i-1)/B+1;
	for(int i=n;i>=1;i--){
		int pos=i+k[i];
		int r=min(b[i]*B,n);
		if(pos>r){
			f[i]=1;
			nxt[i]=pos;
		} 
		else{
			f[i]=f[pos]+1;
			nxt[i]=nxt[pos];
		}
	}
	for(int i=1;i<=m;i++){
		int op=read(),id=read();
		if(op==0){
			k[id]=read();
			update(id);
			continue;
		}
		int ans=0;
		while(nxt[id]<=n){
			ans+=f[id];
			id=nxt[id];
		}
		while(id+k[id]<=n)id+=k[id],ans++;
		cout<<id<<' '<<ans+1<<'\n';
	}
	return 0;
}