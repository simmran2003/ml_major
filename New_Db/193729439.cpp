/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define eb emplace_back
#define PI 3.14159265359
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define BIT(x,i) (1&((x)>>(i)))
#define MASK(x) (1LL<<(x))
#define task "tnc"  
typedef long long ll;
const ll INF=1e18;
const int maxn=1e6+5;
const int mod=1e9+7;
const int mo=998244353;
using pi=pair<ll,ll>;
using vi=vector<ll>;
using pii=pair<pair<ll,ll>,ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n,m;
int a[maxn];
int jump[maxn];
int cnt[maxn];
const int blk=350;
pair<int,int>get(int x){
	int sum=1;
	while(true){
		sum+=cnt[x];
		x=jump[x];
		if(x==jump[x])break;
	}
	return {x,sum};
}
void update(int x){
	int j=x/blk;
	for(int i=x;i>=j*blk;i--){
		if(i+a[i]>=n){
			jump[i]=i;
			cnt[i]=0;
		}
		else if((i+a[i])/blk!=i/blk){
			cnt[i]=1;
			jump[i]=i+a[i];
		}
		else{
			cnt[i]=cnt[i+a[i]]+1;
			jump[i]=jump[i+a[i]];
		}
	}
}
signed main()
{
	cin.tie(0),cout.tie(0)->sync_with_stdio(0);
    //freopen(task".inp" , "r" , stdin);
    //freopen(task".out" , "w" , stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(i==n-1 || i/blk != (i+1)/blk)update(i);
	}
	for(int i=1;i<=m;i++){
		int type;
		cin>>type;
		if(type==1){
			int x;
			cin>>x;
			x--;
			pair<int,int>k=get(x);
			cout<<k.fi+1<<" "<<k.se<<"\n";
		}
		else{
			int x,y;
			cin>>x>>y;
			x--;
			a[x]=y;
			update(x);
		}
	}
    return 0;
}

// 3 1 1 1 1 2 8 2
// 0     3 4 5   