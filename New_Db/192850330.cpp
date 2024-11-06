#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,k;
int a[N];
int dp[N*N];
int main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=0;i<=a[n]*k;i++)dp[i]=1e9;
	int L=a[1]*k,R=a[n]*k;
	dp[L]=0;
	for(int i=2;i<=n;i++)a[i]-=a[1];
	for(int i=L;i<=R;i++){
		for(int j=2;j<=n;j++){
			if(i+a[j]>R)break;
			dp[i+a[j]]=min(dp[i+a[j]],dp[i]+1);
		}
	}
	for(int i=L;i<=R;i++){
		if(dp[i]<=k)cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
}

	   		  			  		 	   	        	