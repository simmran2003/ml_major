#include <bits/stdc++.h>
#define int long long 
#define pb push_back
using namespace std;
const int INF=2505;
const int INFN=3e6+5;
struct _node_data{
	int x,y,z;
}aa[INFN<<1];
int n,Map[INF][INF],fa_set[INF],tot,fath[INF][25],dis_[INF][25];
int find_set(int x) {return x==fa_set[x]?x:fa_set[x]=find_set(fa_set[x]);}
struct _node_edge{
	int to_,next_,disv_;
}edge[INF<<1];
int tot2,head[INF],dep[INF];
void add_edge(int x,int y,int z) {
	edge[++tot2]={y,head[x],z};
	head[x]=tot2;
}
void DFS(int x,int fa) {
	fath[x][0]=fa;dep[x]=dep[fa]+1;
	int xx=__lg(dep[x]);
	for (int i=1;i<=xx;i++) {
		fath[x][i]=fath[fath[x][i-1]][i-1];
		dis_[x][i]=max(dis_[x][i-1],dis_[fath[x][i-1]][i-1]);
	}
	for (int i=head[x];i;i=edge[i].next_) {
		int v=edge[i].to_,d=edge[i].disv_;
		if (v==fa) continue;
		dis_[v][0]=d;
		DFS(v,x);
	}
	return ;
}
int LCA(int x,int y) {
	if (dep[x]<dep[y]) swap(x,y);
	int sum=0;
	while (dep[x]!=dep[y]) {
		sum=max(sum,dis_[x][__lg(dep[x]-dep[y])]);
		x=fath[x][__lg(dep[x]-dep[y])];
	}
//	cout<<x<<" "<<y<<" "<<sum<<" kelke\n";
	if (x==y) return sum;
	for (int i=__lg(dep[x]);~i;i--) {
		int xx=fath[x][i],yy=fath[y][i];
		if (xx==yy) continue;
		sum=max(sum,dis_[x][i]);
		sum=max(sum,dis_[y][i]);
		x=xx;y=yy;
	}
	sum=max(sum,dis_[x][0]);
	sum=max(sum,dis_[y][0]);
	return sum;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>Map[i][j];
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) {
			if (Map[i][j]!=Map[j][i]) {
				cout<<"NOT MAGIC\n";
				return 0;
			}
		}
	for (int i=1;i<=n;i++)
		if (Map[i][i]) {
			cout<<"NOT MAGIC\n";
			return 0;
		}
	for (int i=1;i<=n;i++) {
		for (int j=i+1;j<=n;j++)
			aa[++tot]={i,j,Map[i][j]};
	}
	sort(aa+1,aa+1+tot,[](_node_data xx,_node_data yy){return xx.z<yy.z;});
	for (int i=1;i<=n;i++) fa_set[i]=i;
	for (int i=1;i<=tot;i++) {
		int x=find_set(aa[i].x),y=find_set(aa[i].y);
		if (x==y) continue;
//		cout<<aa[i].x<<" "<<aa[i].y<<" "<<aa[i].z<<" over?\n";
		fa_set[x]=y;
		add_edge(aa[i].x,aa[i].y,aa[i].z);
		add_edge(aa[i].y,aa[i].x,aa[i].z);
	}
	DFS(1,0);
//	cout<<LCA(1,2)<<" keqe\n";
//	cout<<dis_[3][0]<<" qweqw\n";
	for (int i=1;i<=n;i++) {
		for (int j=i+1;j<=n;j++) {
			int xx=LCA(i,j);
			if (xx<Map[i][j]) {
				cout<<"NOT MAGIC\n";
				return 0;
			}
		}
	}
	cout<<"MAGIC\n";
	return 0;
}