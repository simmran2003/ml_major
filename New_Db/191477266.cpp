#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define pb push_back

using namespace std;

int32_t main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	priority_queue<int>pq;
	int ans=0;
	for(int i=0;i<n;i++){
		if(!pq.empty() && pq.top()>arr[i]){
			ans+=pq.top()-arr[i];
			pq.pop();
			pq.push(arr[i]);
		}
		pq.push(arr[i]);
	}
	cout<<ans<<endl;
}
  	 		 	   			 					    	  	 		