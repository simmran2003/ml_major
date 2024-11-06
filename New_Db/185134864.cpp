#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
 
ll n, m, s, f, pos, val, curstep;
map<ll, pair<ll,ll>> step;

//true jika xenia sedang mengawasi spy a
bool checkXenia(ll a, pair<ll,ll> step){
	return (step.fi <= a && a <= step.se);
}
 
int main(){
	
	cin >> n >> m >> s >> f;
	for(int i = 1; i <= m; i++){
		ll p, q, r;
		cin >> p >> q >> r;
		step[p] = {q, r};
	}
	val = (s < f ? 1 : -1); 
	pos = s;
	curstep = 1;
	while(pos != f){
		if(!checkXenia(pos, step[curstep]) && !checkXenia(pos+val, step[curstep])){
			pos = (val==1 ? pos+1 : pos-1);
			cout << (val==1 ? "R" : "L");
			curstep++;
		} else {
			curstep++;
			cout << "X";
		}
	}
 
	return 0;
}