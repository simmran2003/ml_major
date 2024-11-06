#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fio ios_base::sync_with_stdio(0);cin.tie(NULL)
#define endl '\n'
#define MAXN ((int)(5e5 + 5))
typedef vector<int> vi;
typedef pair<int,int> pii;


signed main()
{
	int n,res = 0;
	priority_queue<int> pq;
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
      
}
   	 									   		   	   		 		