#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
vector<ll> a;
vector<vector<int>> factors;

void solve(){
	factors.resize(m+1);
	for(int i = 1;i<=m;i++){
		for(int j = i;j<=m;j+=i){
			factors[j].push_back(i);
		}
	}
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		mp[a[i]]++;
	}
	ll ans = 0;
	ll anslcm = 1;
	for(int i = 1;i<=m;i++){
		ll cur =0;
		for(auto &j:factors[i]){
			cur += mp[j];
		}
		if(ans<cur){
			ans=cur;
			anslcm =i;
		}
	}
	if(ans==0){
		cout<<1<<' '<<0<<endl;
		return;
	}
	vector<int> v;
	for(int i = 0;i<n;i++)
		if(anslcm%a[i]==0)
			v.push_back(i);
	ll ansl = a[v[0]];
	for(auto &i:v)ansl = lcm(a[i],ansl);
	cout<<ansl<<' '<<v.size()<<endl;
	for(auto &i:v)cout<<i+1<<' ';cout<<endl;
}

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	a = vector<ll>(n);
	for(auto &i:a)cin >> i;
	solve();
}
