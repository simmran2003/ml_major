#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;
#define int long long int
#define MAXN 105
#define nd second
#define st first 
#define pb push_back
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef vector<int> vi;
typedef vector<vi> vivi;
typedef pair<int, int> pii;
int n,ans,arr[5005],dp[2][5005],ar[5005];

signed main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        ar[i]=arr[i];
    }
    sort(ar+1,ar+n+1);
    for(int i=1;i<=n;i++){
        dp[1][i]=max(arr[1]-ar[i],0ll);
        // cout << dp[1][i] << ' ';
    }
    // cout << endl;
    dp[1][0]=1e18;
    dp[0][0]=1e18;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i%2){
                dp[1][j]=min(dp[0][j]+abs(arr[i]-ar[j]),dp[1][j-1]);
                // cout << dp[1][j] << ' ';
            }
            else{
                dp[0][j]=min(dp[1][j]+abs(arr[i]-ar[j]),dp[0][j-1]);
                // cout << dp[0][j] << ' ';
            }
        }
        // cout << endl;
    }
    cout << dp[n%2][n] << endl;
}
       	 	  	 				  			      		