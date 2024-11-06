#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long int n,tt[500010],i,a=0,b=0,ans;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tt[i];
    }
    cin>>s;
    for(int i=0;i<n;++i){
        if(s[i]=='B') a+=tt[i];
    }
    ans=a;b=a;
    for(i=0;i<n;i++){
        if(s[i]=='B') a-=tt[i];
        else a+=tt[i];
        if(a>ans) ans=a;
    }
    for(i=n-1;i>=0;i--){
        if(s[i]=='B') b-=tt[i];
        else b+=tt[i];
        if(b>ans) ans=b;
    }
    cout<<ans;
    return 0;
}
   				  			 	   	 	 	 	  					