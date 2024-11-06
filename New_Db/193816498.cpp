// LUOGU_RID: 102258558
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5000;
#define F first
#define S second
int dp[N],g[N],src[N],dfn[N],dep[N],fa[N][17],vis[N],op[N],x[N],ans[N],vet[N],stk[N];
int n,q,u,v,tim;
vector<int> G[N];
vector<pair<int,int> > Tr[N];
int cmp(int i, int j){ return dfn[i]<dfn[j]; }
void dfs(int u, int f){
	dfn[u]=++tim,dep[u]=dep[f]+1,fa[u][0]=f;
	for (int i=1; i<=16; i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for (int v:G[u]) if (v!=f) dfs(v,u);
}
int LCA(int u, int v){
	if (u==v) return u;
	if (dep[u]<dep[v]) swap(u,v);
	int d=dep[u]-dep[v];
	for (int i=16; ~i; i--) if (d&(1<<i)) u=fa[u][i];
	if (u==v) return u;
	for (int i=16; ~i; i--) if (fa[u][i]^fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void Add(int u, int v){ Tr[u].push_back({v,dep[v]-dep[u]}); }
void dfs1(int u){
	for (auto v:Tr[u]) dfs1(v.F),g[v.F]=dp[u],dp[u]=min(dp[u],dp[v.F]+v.S);
	if (src[u]) dp[u]=0; int cur=1e9;
	for (auto it=Tr[u].rbegin(); it!=Tr[u].rend(); it++){
		int v=(*it).F; g[v]=min(g[v],cur);
		cur=min(cur,dp[v]+(*it).S);
	}
}
void dfs2(int u, int d){
	dp[u]=min(dp[u],g[u]+d);
	for (auto v:Tr[u]){
		g[v.F]=min(g[v.F],g[u]+d);
		if (src[u]) g[v.F]=0;
		dfs2(v.F,v.S);
	}
}
void Clr(int u){
	dp[u]=g[u]=1e9,vis[u]=src[u]=0;
	for (auto v:Tr[u]) Clr(v.F); Tr[u].clear();
}
void solve(int l, int r){
	if (l==r) return;
	int mid=(l+r)>>1,len=1,top=1;
	solve(l,mid),solve(mid+1,r);
	vet[len]=stk[top]=1; vis[1]=1;
	for (int i=l; i<=r; i++)
		if (!vis[x[i]]) vet[++len]=x[i],vis[x[i]]=1;
	sort(vet+1,vet+1+len,cmp);
	for (int i=1; i<=len; i++){
		if (vet[i]==1) continue;
		while (LCA(vet[i],stk[top])!=stk[top]){
			if (LCA(vet[i],stk[top-1])==stk[top-1]){
				int u=LCA(vet[i],stk[top]); Add(u,stk[top--]);
				if (u!=stk[top]) stk[++top]=u;
			} else Add(stk[top-1],stk[top]),top--;
		}
		stk[++top]=vet[i];
	}
	for (int i=1; i<top; i++) Add(stk[i],stk[i+1]);
	for (int i=l; i<=mid; i++) if (op[i]==1) src[x[i]]=1;
	dfs1(1),dfs2(1,1);
	for (int i=mid+1; i<=r; i++) if (op[i]==2) ans[i]=min(ans[i],dp[x[i]]);
	Clr(1);
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1; i<n; i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs(1,0); op[1]=x[1]=1;
	for (int i=2; i<=q+1; i++) scanf("%d%d",&op[i],&x[i]);
	memset(dp,0x3f,sizeof(dp));
	memset(g,0x3f,sizeof(g));
	memset(ans,0x3f,sizeof(ans));
	solve(1,q+1);
	for (int i=1; i<=q+1; i++) if (op[i]==2) printf("%d\n",ans[i]);
}
