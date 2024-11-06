#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 1000 + 5, M = (1 << 21) + 5, Mod = 998244353, G = 3;
ll p[M] = {};

inline ll power(ll x, ll y){
	ll res = 1;
	while(y){
		if(y & 1) res = res * x % Mod;
		x = x * x % Mod, y >>= 1;
	}
	return res;
}

inline ll inv(ll x){
	return power(x, Mod - 2);
}

inline void NTT(ll x[], ll n, ll y){
	memset(p, 0, sizeof(p));
	for(ll i = 0 ; i < n ; i ++){
		p[i] = p[i >> 1] >> 1;
		if(i & 1) p[i] |= n >> 1;
		if(i < p[i]) swap(x[i], x[p[i]]);
	}
	for(ll B = 2 ; B <= n ; B <<= 1){
		ll g = power(y, (Mod - 1) / B);
		for(ll i = 0 ; i < n ; i += B) for(ll j = i, w = 1 ; j < (i | (B >> 1)) ; j ++, w = w * g % Mod){
			ll l = x[j], r = x[j | (B >> 1)] * w % Mod;
			x[j] = (l + r) % Mod, x[j | (B >> 1)] = (l - r + Mod) % Mod;
		}
	}
}

ll n = 0, m = 1 << 20, k = 0, A[M] = {}, B[M] = {};

int main(){
	scanf("%lld %lld", &n, &k);
	for(ll i = 1, a = 0 ; i <= n ; i ++){
		scanf("%lld", &a);
		A[a] = 1;
	}
	B[0] = 1;
	while(k){
		NTT(A, m, G);
		if(k & 1){
			NTT(B, m, G);
			for(ll i = 0 ; i < m ; i ++) B[i] = A[i] * B[i] % Mod;
			NTT(B, m, inv(G));
			for(ll i = 0, c = inv(m) ; i < m ; i ++) B[i] = B[i] * c % Mod;
			for(ll i = 0 ; i < m ; i ++) B[i] = min(B[i], 1ll);
		}
		for(ll i = 0 ; i < m ; i ++) A[i] = A[i] * A[i] % Mod;
		NTT(A, m, inv(G));
		for(ll i = 0, c = inv(m) ; i < m ; i ++) A[i] = A[i] * c % Mod;
		for(ll i = 0 ; i < m ; i ++) A[i] = min(A[i], 1ll);
		k >>= 1;
	}
	for(ll i = 0 ; i < m ; i ++) if(B[i]) printf("%lld ", i);
	return 0;
}

