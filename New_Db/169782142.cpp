#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
const int N=1e3+5;int f[N][N];
struct node{long long x,y;}a[N],b[N];
bool cmp(node x,node y){return x.y<y.y;}
long long area(node a,node b,node c){
  return a.x*b.y-a.y*b.x+b.x*c.y-b.y*c.x+c.x*a.y-c.y*a.x;
}
bool toleft(node a,node b,node c){
  if(c.y<=a.y || c.y>b.y) return 0;
  return area(a,b,c)>0;
}
int n,m;
int main(){
	cin>>n>>m;
    for(int i=1;i<=n;++i)  scanf("%lld%lld",&a[i].x,&a[i].y);
    for(int i=1;i<=m;++i)  scanf("%lld%lld",&b[i].x,&b[i].y);
    sort(a+1,a+n+1,cmp);
	int ans=0;
    for(int i=1;i<n;++i)
      for(int j=i+1;j<=n;++j)
        for(int k=1;k<=m;++k)
          if(toleft(a[i],a[j],b[k])) f[i][j]++;
    for(int i=1;i<n;++i)
      for(int j=i+1;j<n;++j)
        for(int k=j+1;k<=n;++k)
          if(f[i][j]+f[j][k]==f[i][k]) ans++;
    printf("%d\n",ans); 
    return 0;
}
