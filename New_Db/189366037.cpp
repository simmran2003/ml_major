#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,p;
vector<string> s;

void solve(){
	reverse(s.begin(),s.end());
	ll cur = 0;
	ll ans  =0;
	for(ll i = 0;i<n;i++){
		if(s[i].size()==4)cur *= 2;
		else cur = cur*2+1;
		ans += cur*p/2;
	}
	cout<<ans<<endl;
}

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> n >> p;
	s = vector<string>(n);
	for(int i = 0;i<n;i++){
		cin >> s[i];
	}
	solve();
}
