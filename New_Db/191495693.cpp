#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int32_t main(){
    int n,ans=0;
    cin >> n;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        pq.push(x);
        if(i!=0){
            if(x<pq.top()){
                ans+=pq.top()-x;
                pq.pop();
                pq.push(x);
            }
        }
    }
    cout << ans;
    return 0;
}

							   	 	 	  		 		     		 	