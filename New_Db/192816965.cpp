#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    long long int n,a[500010],i,t=0,u=0,ans;
    string s;
    cin>>n;
    for(i=0;i<n;i++){cin>>a[i];}
    cin>>s;
    for(i=0;i<n;i++)if(s[i]=='B')t+=a[i];
    ans=t;u=t;
    for(i=0;i<n;i++)
    {
        if(s[i]=='B')t-=a[i];
        else t+=a[i];
        if(t>ans)ans=t;
    }
    for(i=n-1;i>=0;i--)
    {
        if(s[i]=='B')u-=a[i];
        else u+=a[i];
        if(u>ans)ans=u;
    }
    cout<<ans;
    return 0;
}
 				 	   	  	 		 	 						  		