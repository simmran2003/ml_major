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
const int N=2e5+100;
const int M=2e5+100;
typedef pair<double,double>pdd;
typedef pair<ull,ull>puu;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<ld,ld>pDD;
bool a[N];
void solve(){
	int n,p;cin>>n>>p;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		if(s=="half")a[i]=0;
		else a[i]=1;
	}ll ans=0,cur=0.0;
	for(int i=n;i>=1;i--){
		if(a[i])cur=(cur+5)*2;
		else cur*=2;
		ans+=cur/2;
	}ans=ans*p/10;
	cout<<ans<<endl;
}
signed main(){IOS;
	int T=1;//scanf("%d",&T);
	while(T--)solve();
	return 0;
}

