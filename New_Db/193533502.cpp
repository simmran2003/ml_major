#include<bits/stdc++.h>
using namespace std;
int const M=100100;int i,n,m,x,opt,block;
int a[M],L[M],R[M],bel[M],nxt[M],dis[M];
int read(){
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x;
}
void update(int x){
	for (int i=R[x];i>=L[x];i--)
		dis[i]=i+a[i]>R[x]?1:dis[i+a[i]]+1,
		nxt[i]=i+a[i]>R[x]?i+a[i]:nxt[i+a[i]];
}
void query(int x){int id,res=0;
	for (int i=x;i<=n;i=nxt[i])
		res+=dis[i],id=i;
	for (int i=id;i<=n;i+=a[i])
		id=i;
	printf("%d %d\n",id,res);
}
int main(){
	n=read();m=read();
	block=(int)ceil(sqrt(n));
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=n;i++) bel[i]=(i-1)/block+1;
	for (i=1;i<=bel[n];i++) L[i]=R[i-1]+1,R[i]=R[i-1]+block;
	R[bel[n]]=n;for (i=1;i<=bel[n];i++) update(i);
	while (m--){ opt=read();x=read();
		if (!opt) a[x]=read(),update(bel[x]);
		if (opt) query(x);
	}
	return 0;
} 