#include<bits/stdc++.h>

typedef  long long ll;
typedef  unsigned long long ull;

# define MAX 1000
#define YU_GI_OH 	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mem(a,val) memset(a, val, sizeof(a));
#define mem(ml,val) fill(ml.begin(), ml.end(), val);
#define debug(v) for(auto&i:v)cout<<i<<" ";
//
template<class... Args>
inline void put(Args&... args) { (std::cout << ... << args); }
template<class... Args>
inline void read(Args&... args) { (std::cin >> ... >> args); }
//
const ll mod = 1e9 + 7;
std::string YorN[2] = { "Yes\n","No\n" };

using namespace std;
///////////////////////////////////////////////////////////////////////////////

int main() {

    YU_GI_OH
        //
        //
        int tc = 1;
    //cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<ll>>prf(n+2, vector<ll>(2));
        vector<vector<ll>>suff(n+2, vector<ll>(2));
        vector<ll>v(n+2);
        string s;
        for (int i = 1; i <= n;i++)cin >> v[i];
        cin >> s;
        s = "#" + s;
        //
        for (int i = 1; i <= n; i++) {
            prf[i][0] = prf[i - 1][0] ;
            prf[i][1] = prf[i - 1][1] ;
            if (s[i] == 'A')prf[i][0] += v[i];
            else prf[i][1] += v[i];
        }
        for (int i = n; i >0; i--) {
            suff[i][0] = suff[i + 1][0] ;
            suff[i][1] = suff[i + 1][1] ;
            if (s[i] == 'A')suff[i][0] += v[i];
            else suff[i][1] += v[i];
        }
        //
        ll ans = max(suff[1][1],prf[n][1]);
        for (int i = 1; i <= n; i++) {
            ll cnt = (suff[i+1][1]) + (prf[i][0]);
            ans = max(ans, cnt);
        }
        //
        for (int i = n; i >= 1; i--) {
            ll cnt = (prf[i - 1][1]) + (suff[i][0]);
            ans = max(ans, cnt);
        }
        put(ans, "\n");
    }

}