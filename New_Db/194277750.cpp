#include"bits/stdc++.h"
using namespace std;

int main(){
	int n; cin>>n;
	int arr[n];
	map<int,int> mp;
	vector<string> ans;
	for(int i=0;i<n;i++) {cin>>arr[i]; mp[arr[i]]++;}
	while(1){
	    if(mp[1] && mp[3] && mp[6]){
	        ans.push_back("1 3 6");
	        mp[1]--; mp[3]--; mp[6]--;
	    }
	    else if(mp[1] && mp[2] && mp[6]){
	        ans.push_back("1 2 6");
	        mp[1]--; mp[2]--; mp[6]--;
	    }
	    else if(mp[1] && mp[2] && mp[4]){
	        ans.push_back("1 2 4");
	        mp[1]--; mp[2]--; mp[4]--;
	    }
		else break;
	}
	if((int)ans.size()*3 != n) cout<<-1<<endl;
	else{
		for(auto it: ans) cout<<it<<endl;
	}

}