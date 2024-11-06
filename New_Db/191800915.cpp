#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	ll n; cin >> n;

	priority_queue<ll> pq;

	ll ans = 0;

	for (ll i = 0; i < n; i++)
	{
		ll x; cin >> x;

		if (pq.empty())
		{
			pq.push(x);
		}
		else
		{
			if (pq.top() > x)
			{
				ans += pq.top() - x;

				pq.pop();

				pq.push(x);
			}

			pq.push(x);
		}
	}
	cout << ans << endl;
}
  			   			  	  	 			       	 	