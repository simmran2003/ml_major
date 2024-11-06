#include <bits/stdc++.h>
using namespace std;
int main(){
	int r,h;
	cin>>r>>h;
	int l=h % r,ans=h/r*2+1;
	if(l>=(double)r/2.0*sqrt(3))ans+=2;
	else if(l>=(double)r/2)ans++;
	cout<<ans<<endl;
	return 0;//
}
 		   	  	  		   	 	    			 			