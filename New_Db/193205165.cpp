#include <bits/stdc++.h>
using namespace std;

/*<DEBUG>*/
#define tem template <typename 
#define can_shift(_X_, ...) enable_if_t<sizeof test<_X_>(0) __VA_ARGS__ 8, debug&> operator<<(T i)
#define _op debug& operator<<
tem C > auto test(C *x) -> decltype(cerr << *x, 0LL);
tem C > char test(...);
tem C > struct itr{C begin, end; };
tem C > itr<C> get_range(C b, C e) { return itr<C>{b, e}; }
struct debug{
#ifdef _LOCAL
	~debug(){ cerr << endl; }
	tem T > can_shift(T, ==){ cerr << boolalpha << i; return *this; }
	tem T> can_shift(T, !=){ return *this << get_range(begin(i), end(i)); }
	tem T, typename U > _op (pair<T, U> i){ 
		return *this << "< " << i.first << " , " << i.second << " >"; }
	tem T> _op (itr<T> i){
		*this <<  "{ ";
		for(auto it = i.begin; it != i.end; it++){
			*this << " , " + (it==i.begin?2:0) << *it;
		}
		return *this << " }";
	}
#else
tem T> _op (const T&) { return *this; }
#endif 
};

tem T>
string _ARR_(T* arr, int sz){
	string ret = "{ " + to_string(arr[0]); 
	for(int i = 1; i < sz; i++) ret += " , " +  to_string(arr[i]);
	ret += " }"; return ret;
}

#define exp(...) " [ " << #__VA_ARGS__ << " : " << (__VA_ARGS__) << " ]"
/*</DEBUG>*/

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef pair<int, int> pii;
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define TC int __TC__; cin >> __TC__; while(__TC__--)
#define ar array

const int INF = 1e9 + 7;

const int N = 100005, X = 320;

int n, m, a[N], out[N], jmp[N];

void calc(int start, int end){
	for(int i = start; i >= end; --i){
		if(a[i] + i > n || i/X < (a[i] + i) / X){
			out[i] = i;
			jmp[i] = 1;
		}
		else{
			out[i] = out[a[i] + i];
			jmp[i] = 1 + jmp[a[i] + i];
		}
	}
	return;
}


int main()
{
	FAST;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];

	calc(n, 0);

	for(int i = 0; i < m; ++i){
		int t; cin >> t;

		if(!t){
			int x, v; cin >> x >> v;
			a[x] = v;
			calc(min(n, (x/X)*X + X), (x/X)*X);
		}else{
			int x; cin >> x;
			int jumps = 0;

			while(out[x] + a[out[x]] <= n){
				jumps += jmp[x];
				x = out[x] + a[out[x]];
			}
			jumps += jmp[x];
			cout << out[x] << ' ' << jumps << '\n'; 
		}
	}

	return 0;
}


