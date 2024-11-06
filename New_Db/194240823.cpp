//#pragma GCC optomize ("Ofast")
//#pragma GCC optomize ("unroll-loops")
//#pragma GCC target ("avx,avx2,fma")
#include <bits/stdc++.h>
  
#define F first
#define S second 
#define ll long long
#define all(x) (x.begin(), x.end());
#define uint unsigned int
#define pb push_back
#define	ios	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define int ll
 
using namespace std;
  
const int N = 1e5+9;
//const ll INF = 1e18 , inf = 1e9 , mod = 1e9+7;

int n,m;
int a[N];
int cnt[N];
int last[N];

int BLOCK=300;

void upd(int x){
	int l=x*BLOCK,r=min(l+BLOCK,n)-1;
	for(int i=r;i>=l;i--){
		if(i+a[i]>r){
			cnt[i]=1;
			last[i]=i;
		}
		else{
			cnt[i]=cnt[i+a[i]]+1;
			last[i]=last[i+a[i]];
		}
	}
}

signed main(){
//  	freopen(".in", "r", stdin);
//  	freopen(".out", "w", stdout);
    ios;
	int tt=1;
//	cin>>tt;
	while(tt--){
		cin>>n>>m;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i*BLOCK<n;i++)upd(i);
		while(m--){
			int q;
			cin>>q;
			if(q==0){
				int ind,val;
				cin>>ind>>val;
				ind--;
				a[ind]=val;
				upd(ind/BLOCK);
			}
			else{
				int ind;
				cin>>ind;
				int ans=0;
				ind--;
				while(ind<n){
					ans+=cnt[ind];
					ind=last[ind];
					if(ind+a[ind]<n)ind+=a[ind];
					else break;
				}
				cout<<ind+1<<" "<<ans<<'\n';
			}
		}
	}
}