#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
  #define x first
  #define y second
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0);
#define endl '\n'
#define int long long
#define ll long long
#define db double
#define inf 0x3f3f3f3f
#define ad(i,j,k,z) for(int i = (j);i <= (k);i += (z))
#define su(i,j,k,z) for(int i = (j);i >= (k);i -= (z))
#define be(i,j,k) (i)?j:k
#define PII pair<int, int>
#define maxv *max_element
#define minv *min_element
#define NO cout << "NO" << '\n';
#define YES cout << "YES" << '\n';
using namespace std;
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int> > up;
//---------------------------------------------------
int qmi(int a, int k, int p){ int res = 1 % p; while (k){ if (k & 1) res = res * a % p;
        a = a * a % p;k >>= 1;} return res;}
int ksm(int a, int k){ int res = 1; while (k){ if (k & 1) res = res * a;
        a = a * a;k >>= 1;} return res;}
//----------------------------------------------------
const int N1 = 2e5 + 10, mod = 1e9 + 7;

int fa[N1], infa[N1];
void initcp(int n){ fa[0] = infa[0] = 1; for (int i = 1; i < n; i ++ ) {
        fa[i] = fa[i-1] * i % mod; infa[i] = infa[i-1] * qmi(i, mod - 2, mod) % mod;}}
int C(int a, int b){ if(a < b) return 0; return fa[a] * infa[a-b] % mod * infa[b] % mod;}
int CL(int a,int b){ if(a < b) return 0; int down = 1, up = 1; 
    for(int i = a, j = 1; j <= b; i -- ,j ++){ up = up * i % mod; down = down * j % mod;}
    return up * qmi(down, mod-2, mod) % mod; }    
int Lucas(int a, int b){ if(a < mod && b < mod) return C(a,b);
    return Lucas(a/mod, b/mod) * C(a % mod, b % mod) % mod;}
int P(int a, int b){ if(a < b) return 0; return fa[a] * infa[a-b] % mod;}
/*-----------------------------------------------------------*/
const int N2 = 1e6 + 10;

int cntt, primes[N2];
bool stt[N2];
void initpr(int n){ for(int i = 2; i <= n; i ++){ if(!stt[i]) primes[cntt ++] = i;
        for(int j = 0; primes[j] * i <= n; j ++){ stt[primes[j] * i] = true;
            if(i % primes[j] == 0) break;} } }
int gcd(int a, int b){return b ? gcd(b, a % b) : a;}
/*----------------------------------------------------------*/
// 返回末尾的1
int lowbit(int x){ return x & -x; }
const int N = 1e6 + 10;

void solve()
{
	int n;
	cin >> n;
	vector<int> p(n);
	vector<PII> a(n);
	for(int i = 0; i < n; i ++) cin >> p[i];
	string s;
	cin >> s;
	int aa = 0,bb = 0;
	for(int i = 0; i < n; i ++)                                                                                                                                                                                                                 
	{
	    if(s[i] == 'A') aa += p[i];
	    else bb += p[i];
	    a[i].x = aa;
	    a[i].y = bb;
	}
	int ma = bb;
	//cout << aa << " " << bb << endl;
	int cc = aa;
	ma = max(ma, cc);
	for(int i = 0; i < n; i ++)
	{
	    //cout << a[i].x << " " << a[i].y << endl;
	    cc = bb - a[i].y + a[i].x;
	    ma = max(ma, cc);
	}
	for(int i = n-1; i >= 0; i --)
	{
	    int cc = bb - (bb - a[i].y) + (aa - a[i].x);
	    ma = max(ma, cc);
	}
	cout << ma << endl;
}

signed main()
{
    IOS
    initcp(1010);
    initpr(1010);
    int T = 1;
    //cin >> T;
    while(T --)
    {
        solve();
    }
    
    return 0;
}
  			   			 		 	 				 			 		 		