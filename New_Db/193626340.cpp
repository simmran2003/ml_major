#pragma optimize("Bismillahirrahmanirrahim")
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█■█
//█─█─█▄─█▄─█─█─█─█
//Allahuekber
//ahmet23 orz...
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
#define author tolbi
#include <bits/stdc++.h>
#ifdef LOCAL
	#include "23.h"
#endif
#define int long long
#define endl '\n'
#define vint(x) vector<int> x
#define deci(x) int x;cin>>x;
#define decstr(x) string x;cin>>x;
#define cinarr(x) for (auto &it : x) cin>>it;
#define coutarr(x) for (auto &it : x) cout<<it<<" ";cout<<endl;
#define sortarr(x) sort(x.begin(),x.end())
#define sortrarr(x) sort(x.rbegin(),x.rend())
#define det(x) cout<<"NO\0YES"+x*3<<endl;
#define INF LONG_LONG_MAX
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		vint(arr(n));
		cinarr(arr);
		vector<int> barr;
		map<int,bool> mp;
		for (int i = 0; i < n; ++i)
		{
			mp[arr[i]]=true;
		}
		for (auto it : mp) {
			barr.push_back(it.first);
		}
		vector<vector<int>> dp(2,vector<int>(barr.size(),-1));
		dp[0].back()=abs(arr.back()-barr.back());
		for (int i = barr.size()-2; i >= 0; i--){
			dp[0][i]=min(dp[0][i+1],abs(arr.back()-barr[i]));
		}
		for (int i = n-2; i >= 0; i--){
			dp[1].back()=abs(arr[i]-barr.back())+dp[0].back();
			for (int j = barr.size()-2; j >= 0; j--){
				dp[1][j] = min(dp[1][j+1],dp[0][j]+abs(arr[i]-barr[j]));
			}
			swap(dp[0],dp[1]);
		}
		cout<<dp[0][0]<<endl;
	}
}
	 	    	 		 	  	  			  	 	  	 	