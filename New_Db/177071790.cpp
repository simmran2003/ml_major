// LUOGU_RID: 90642411
#include<stdio.h>
#include<bits/stdc++.h>
#define fir first
#define sec second
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 int128;
typedef __uint128_t uint128;
typedef pair<int,int> pii;
template<typename type>
inline void chmin(type &x,const type &y)
{
	if(x>y)
		x=y;
}
template<typename type>
inline void chmax(type &x,const type &y)
{
	if(x<y)
		x=y;
}
constexpr int Max=1e4+10;
constexpr ll mod=1'000'000'007;
inline void mod_add(ll &x,const ll &y)
{
	x+=y;
	if(x>=mod)
		x-=mod;
}
char a[3][Max],b[3][Max];
int n;
ll f[Max][8];
ll solve(const char (&a)[3][Max])
{
	memset(f,0,sizeof(f));
	f[0][7]=1;
	for(int i=1;i<=n;++i)
	{
		int s=0;
		for(int j=0;j<3;++j)
			if(a[j][i]!='.')
				s|=1<<j;
		f[i][s]=f[i-1][7];
		if(!(s&1))
			f[i][1|s]=f[i-1][6];
		if(!(s&2))
			f[i][2|s]=f[i-1][5];
		if(!(s&4))
			f[i][4|s]=f[i-1][3];
		if(!(s&3))
			f[i][3|s]=(f[i-1][4]+f[i-1][7])%mod;
		if(!(s&6))
			f[i][6|s]=(f[i-1][1]+f[i-1][7])%mod;
		if(!(s&5))
			f[i][5|s]=f[i-1][2];
		if(!(s&7))
			f[i][7|s]=(f[i-1][0]+f[i-1][3]+f[i-1][6])%mod;
	}
	return f[n][7];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	int px=0,py=0;
	for(int i=0;i<3;++i)
		for(int j=1;j<=n;++j)
		{
			cin>>a[i][j];
			if(a[i][j]=='O')
				px=i,py=j;
		}
	ll ans=0;
	for(int k1:{0,1})
		for(int k2:{0,1})
			for(int k3:{0,1})
				for(int k4:{0,1})// up, down, left, right
				{
					if((k1&&px<2)||(k2&&px>0)||(k3&&py<=2)||(k4&&py>=n-1))
						continue;
					bool flag=true;
					memcpy(b,a,sizeof(a));
					if(k1)
						for(int i:{0,1})
						{
							if(a[i][py]!='.')
								flag=false;
							b[i][py]='O';
						}
					if(k2)
						for(int i:{1,2})
						{
							if(a[i][py]!='.')
								flag=false;
							b[i][py]='O';
						}
					if(k3)
						for(int i:{py-2,py-1})
						{
							if(a[px][i]!='.')
								flag=false;
							b[px][i]='O';
						}
					if(k4)
						for(int i:{py+1,py+2})
						{
							if(a[px][i]!='.')
								flag=false;
							b[px][i]='O';
						}
					int tmp=k1+k2+k3+k4;
					if(!tmp||!flag)
						continue;
					if(tmp&1)
						mod_add(ans,solve(b));
					else
						mod_add(ans,mod-solve(b));
				}
	cout<<ans<<"\n";
	return 0;
}