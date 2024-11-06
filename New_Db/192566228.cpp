#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
int main()
{
	ll n,ans=0,arr[5005];
	priority_queue<ll> pq;
	cin >> n;
	for(ll i=1;i<=n;i++)
	{
		cin >> arr[i];
		if(!pq.empty()&&pq.top()>arr[i])
		{
			ans=ans+pq.top()-arr[i];
			pq.pop();
			pq.push(arr[i]);
		}
		pq.push(arr[i]);
	}
	cout << ans << endl;
	return 0;
}

			   	 	     	 	 	        		 	