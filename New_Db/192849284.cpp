#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

namespace Mod9{
	const int Mod = 998244353;
	inline void uadd(int &a, int b){ a += b-Mod; a += (a>>31) & Mod; }
	inline void usub(int &a, int b){ a -= b; a += (a>>31) & Mod; }
	inline void umul(int &a, int b){ a = (int)(1ll*a*b % Mod); }
	inline int add(int a, int b){ return (a+b >= Mod) ? a+b-Mod : a+b; }
	inline int sub(int a, int b){ return (a-b < 0) ? a-b+Mod : a-b; }
	inline int mul(int a, int b){ return (int)(1ll*a*b % Mod); }
	int qpow(int b, ll p){ int ret = 1; while(p){ if(p&1) umul(ret, b); umul(b, b), p >>= 1; } return ret; }
	int fact[1000100], invfact[1000100];
	void initfact(int n){
		fact[0] = 1; for(int i = 1; i <= n; ++i) fact[i] = mul(fact[i-1], i);
		invfact[n] = qpow(fact[n], Mod-2);
		for(int i = n; i >= 1; --i) invfact[i-1] = mul(invfact[i], i);
	}
	inline int C(int n, int m){ return mul(fact[n], mul(invfact[m], invfact[n-m])); }

	int to[1048888], w[1048888];
	int N, bl;
	void dft(int *a, bool idft = 0){
		rep(i, N) if(to[i] < i) swap(a[i], a[to[i]]);
		for(int len = 0; len < bl; ++len) for(int l = 0; l < N; l += (1<<len)<<1)
			for(int i = 0; i < (1<<len); ++i){
				int x = a[l|i], y = mul(a[l|(1<<len)|i], w[i<<(bl-len-1)]);
				a[l|i] = add(x, y), a[l|(1<<len)|i] = sub(x, y);
			}
		if(idft){
			for(int i = 1; i < N-i; ++i) swap(a[i], a[N-i]);
			int invn = qpow(N, Mod-2);
			rep(i, N) umul(a[i], invn);
		}
	}

	void initN(int n){
		bl = 0;
		while((1<<bl) < n) ++bl;
		N = (1<<bl);
		w[0] = 1, w[1] = qpow(3, (Mod-1) / N);
		for(int i = 2; i <= N; ++i) w[i] = mul(w[i-1], w[1]);
		rep(i, N) to[i] = (to[i>>1]>>1) + ((i&1)<<(bl-1));
	}
}

namespace Mod1{
	const int Mod = 1004535809;
	inline void uadd(int &a, int b){ a += b-Mod; a += (a>>31) & Mod; }
	inline void usub(int &a, int b){ a -= b; a += (a>>31) & Mod; }
	inline void umul(int &a, int b){ a = (int)(1ll*a*b % Mod); }
	inline int add(int a, int b){ return (a+b >= Mod) ? a+b-Mod : a+b; }
	inline int sub(int a, int b){ return (a-b < 0) ? a-b+Mod : a-b; }
	inline int mul(int a, int b){ return (int)(1ll*a*b % Mod); }
	int qpow(int b, ll p){ int ret = 1; while(p){ if(p&1) umul(ret, b); umul(b, b), p >>= 1; } return ret; }
	int fact[1000100], invfact[1000100];
	void initfact(int n){
		fact[0] = 1; for(int i = 1; i <= n; ++i) fact[i] = mul(fact[i-1], i);
		invfact[n] = qpow(fact[n], Mod-2);
		for(int i = n; i >= 1; --i) invfact[i-1] = mul(invfact[i], i);
	}
	inline int C(int n, int m){ return mul(fact[n], mul(invfact[m], invfact[n-m])); }

	int to[1048888], w[1048888];
	int N, bl;
	void dft(int *a, bool idft = 0){
		rep(i, N) if(to[i] < i) swap(a[i], a[to[i]]);
		for(int len = 0; len < bl; ++len) for(int l = 0; l < N; l += (1<<len)<<1)
			for(int i = 0; i < (1<<len); ++i){
				int x = a[l|i], y = mul(a[l|(1<<len)|i], w[i<<(bl-len-1)]);
				a[l|i] = add(x, y), a[l|(1<<len)|i] = sub(x, y);
			}
		if(idft){
			for(int i = 1; i < N-i; ++i) swap(a[i], a[N-i]);
			int invn = qpow(N, Mod-2);
			rep(i, N) umul(a[i], invn);
		}
	}

	void initN(int n){
		bl = 0;
		while((1<<bl) < n) ++bl;
		N = (1<<bl);
		w[0] = 1, w[1] = qpow(3, (Mod-1) / N);
		for(int i = 2; i <= N; ++i) w[i] = mul(w[i-1], w[1]);
		rep(i, N) to[i] = (to[i>>1]>>1) + ((i&1)<<(bl-1));
	}
}

int n, k;
int a[1010];
int b[1048888];
bool ok[1048888];

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> k;
	rep(i, n){
		cin >> a[i];
		b[a[i]] = 1;
	}

	Mod9::initN(1<<20);
	Mod9::dft(b);
	rep(i, Mod9::N)
		b[i] = Mod9::qpow(b[i], k);
	Mod9::dft(b, 1);
	rep(i, Mod9::N)
		ok[i] = (bool)(b[i]);
	
	rep(i, Mod9::N)
		b[i] = 0;
	rep(i, n)
		b[a[i]] = 1;

	Mod1::initN(1<<20);
	Mod1::dft(b);
	rep(i, Mod1::N)
		b[i] = Mod1::qpow(b[i], k);
	Mod1::dft(b, 1);
	rep(i, Mod1::N)
		if(ok[i] || b[i])
			cout << i << " ";
	
	cout << "\n";

	return 0;
}