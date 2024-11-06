#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define x first
#define y second
#define NO cout << "NO" << '\n';
#define YES cout << "YES" << '\n';

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef pair<LL, LL> PLL;
typedef unsigned long long ULL;
typedef double long DL;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const int MOD = 998244353, M = 1e5 + 10, N = 5e5 + 10;
int primes[M], cc;
bool st[M];

const LL LL_MAX = LLONG_MAX, LL_MIN = LLONG_MIN;

void init()
{
    for (int i = 2; i <= M; i ++)
    {
        if (!st[i]) primes[cc ++] = i;
        for (int j = 0; primes[j] <= M / i; j ++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int qmi(int a, int k, int p)  // 求a^k mod p
{
    int res = 1 % p;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

LL check(LL n)
{
    int cnt = 0;
    while (n -- ){
        cnt ++;
        n /= 10;
    }
    return cnt;
}

LL find_max(LL n)
{
   LL maxx = 0;
   while (n)
   {
       maxx = max(maxx, n % 10);
       n /= 10;
   }
   return maxx;
}

LL a[N];

void solve()
{
    LL n;
    cin >> n;;
    for (int i = 0; i < n; i ++) cin >> a[i];
    string s;
    cin >> s;
    LL Bob = 0, Alice = 0;
    for (int i = 0; i < n; i ++)
    {
        if (s[i] == 'A') Alice += a[i];
        else Bob += a[i];
    }
    LL ans = Bob, b = Bob, c = Alice;
    for (int i = 0; i < n; i ++)
    {
        if (s[i] == 'A') c -= a[i], b += a[i];
        else c += a[i], b -= a[i];
        ans = max(ans, b);
    }
    
    for (int i = n - 1; i >= 0; i --)
    {
        if (s[i] == 'A') Alice -= a[i], Bob += a[i];
        else Alice += a[i], Bob -= a[i];
        ans = max(ans, Bob);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(15);
    //init();
    int _ = 1;
    //cin >> _;
    while (_ --) solve();
    return 0;
}
		    		  	 		  	  	   	 	 		