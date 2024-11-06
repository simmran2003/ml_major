// LUOGU_RID: 97817066
//Writer: HugeWide
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

inline ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x) {
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),putchar('\n')

#define rep(x,l,r) for(int x=l;x<=r;x++)
#define per(x,r,l) for(int x=r;x>=l;x--)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

const int N=10010;
const int MOD=1e9+7;

void add(int& x,int y) {
	x+=y; if(x>=MOD) x-=MOD;
}

int n;
char a[N][5];
char b[5][N];
char s[N][5];

int f[N][8];
int solve() {
	rep(i,0,n) rep(j,0,7) f[i][j]=0;
	f[0][0]=1;
	rep(i,1,n) {
		if(s[i][0]=='.'&&s[i][1]=='.'&&s[i][2]!='.') {
			add(f[i][0],f[i-1][0]);
		}
		if(s[i][0]!='.'&&s[i][1]=='.'&&s[i][2]=='.') {
			add(f[i][0],f[i-1][0]);
		}
		if(s[i][0]=='.'&&s[i][1]=='.'&&s[i][2]=='.') {
			add(f[i][1],f[i-1][0]),add(f[i][0],f[i-1][1]);
			add(f[i][4],f[i-1][0]),add(f[i][0],f[i-1][4]);
		}
		int x=0;
		rep(j,0,2) if(s[i][j]=='.') x|=1<<j;
		rep(j,0,7) if((j|x)==x) add(f[i][j],f[i-1][j^x]);
	}
//	rep(i,1,n) cout<<s[i][0]<<s[i][1]<<s[i][2]<<'\n';
//	cout<<f[n][0]<<"\n\n";
	return f[n][0];
}

int main() {
	n=read();
	rep(i,0,2) scanf("%s",b[i]+1);
	rep(i,0,2) rep(j,1,n) a[j][i]=b[i][j];
//	rep(i,1,n) cout<<a[i][0]<<a[i][1]<<a[i][2]<<'\n'; cout<<'\n';
	int ans=0; int x=0,y=0;
	rep(i,1,n) rep(j,0,2) if(a[i][j]=='O') x=i,y=j;
	rep(u,0,1) rep(d,0,1) rep(l,0,1) rep(r,0,1) if(u+d+l+r>0) {
		if(u&&!(x>=3&&a[x-1][y]=='.'&&a[x-2][y]=='.')) continue;
		if(d&&!(x<=n-2&&a[x+1][y]=='.'&&a[x+2][y]=='.')) continue;
		if(l&&!(y>=2&&a[x][y-1]=='.'&&a[x][y-2]=='.')) continue;
		if(r&&!(y<=0&&a[x][y+1]=='.'&&a[x][y+2]=='.')) continue;
		rep(i,1,n) rep(j,0,2) s[i][j]=a[i][j]; s[x][y]='X';
		if(u) s[x-1][y]=s[x-2][y]='X';
		if(d) s[x+1][y]=s[x+2][y]='X';
		if(l) s[x][y-1]=s[x][y-2]='X';
		if(r) s[x][y+1]=s[x][y+2]='X';
		int res=solve();
		int rate=(u+d+l+r)%2;
		ans=(ans+res*(rate?1:-1)+MOD)%MOD;
//		cout<<u<<d<<l<<r<<' '<<res<<'\n';
	}
	writeln(ans);
//	rep(i,1,n) rep(j,0,2) s[i][j]=a[i][j];
//	solve();
//	rep(i,1,n) {
//		rep(j,0,7) cout<<f[i][j]<<' '; cout<<'\n';
//	}
	return 0;
}
