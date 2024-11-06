#include<bits/stdc++.h>
#define int long long
using namespace std;

void slove()
{
    int n;
    cin>>n;
    int a[n+10];
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    string s;
    s+='-';
    string aaaaaa;
    cin>>aaaaaa;
    s+=aaaaaa;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='B')
        {
            ans+=a[i];
        }
    }
    int ma=ans,p=ans;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='A')
            p+=a[i];
        else
            p-=a[i];
        ma=max(ma,p);
    }
    p=ans;
    for(int i=n;i>=1;i--)
    {
        if(s[i]=='A')
            p+=a[i];
        else
            p-=a[i];
        ma=max(ma,p);
    }
    cout<<ma<<endl;
}

signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    while (t--)
    {
        slove();
    }
    //system("pause");
    return 0;
}

  		  		    	     		   	  	 	