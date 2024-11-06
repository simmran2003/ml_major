#include <bits/stdc++.h>
#define int ll
#define ff first
#define ss second
#define zort sort
#define endl '\n'
#define pb push_back
#define IMAX INT64_MAX
#define N 200005
#define MOD 1000000007
#define MOD2 998244353
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define cno cout<<"NO"<<endl
#define cyes cout<<"YES"<<endl
#define cendl cout<<endl
#define rset srand(int(time(NULL)));
#define dpset memset(dp,-1,sizeof(dp))
#define isint(x) ceil(x)==floor(x)
#define acm(x) accumulate(all(v),0)
#define sumroot(i) double(1/2)*double((double)sqrt(8*i+1)-1)
#define ssum(x) x*(x+1)/2
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<setprecision(10);
#define allset fast;rset;dpset
using namespace std;
typedef long long ll;
typedef long double ldouble;
typedef string str;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<pair<char,int>> vci;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<double,int> mdi;
typedef map<string,int> msi;
typedef map<int,str> mis;
/*
g++ -Wall -g C:\Users\teoat\OneDrive\Belgeler\temp.cpp -o C:\Users\teoat\OneDrive\Belgeler\a.exe
*/

int n,res;
priority_queue<int> pq;
main()
{
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        int x; cin >> x;
        if(!pq.empty() && pq.top() > x)
        {
            res += pq.top() - x;
            pq.pop();
            pq.push(x);
        }
        pq.push(x);
    }
    cout << res;
      return 0;
      
}