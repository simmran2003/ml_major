#include<bits/stdc++.h>
#define endl '\n'
//#define x first
//#define y second
#define E 2.718282
#define ll long long
//#define int long long
#define ld long double
#define lowbit(x) (x&(-x))
#define	ull	unsigned long long
#define LD(num) ((LD)(1.0*num))
#define D(num) ((double)(1.0*num))
#define all(vec) vec.begin(),vec.end()
#define coutp(p) cout<<setprecision(p);
#define IOS std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
using namespace std;
const ll  inf_ll=0x3f3f3f3f3f3f;
const int inf_int=0x3f3f3f3f;
const ld  Pi=acos(-1.0);
const int inf_mem=0x3f;
const ll  mod=1e9+7;
const ld  eps=1e-6;
const int N=1e6+100;
const int M=2e6+100;
typedef pair<double,double>pdd;
typedef pair<ull,ull>puu;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<ld,ld>pDD;
int a[N],cnt[M];
inline void chk_max(int&a,int&b,int arr[]){a=arr[a]>=arr[b]?a:b;}
inline void chk_min(int&a,int&b,int arr[]){a=arr[a]<=arr[b]?a:b;}
void solve(){
	int n,m;scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<=m)cnt[a[i]]++;
	}							//for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";puts("");
	for(int i=m;i>=1;i--){		//printf("i=%d\n",i);
		for(int j=i+i;j<=m;j+=i)
			cnt[j]+=cnt[i];		//for(int j=1;j<=m;j++)cout<<cnt[j]<<" ";puts("");
	}							//for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";puts("");
	int ans=1;
	for(int i=1;i<=m;i++)
		if(cnt[ans]<cnt[i])
			ans=i;
	printf("%d %d\n",ans,cnt[ans]);
	for(int i=1;i<=n;i++)
		if(ans%a[i]==0)
			printf("%d ",i);
	puts("");
}
signed main(){
	int T=1;//scanf("%d",&T);
	while(T--)solve();
	return 0;
}

