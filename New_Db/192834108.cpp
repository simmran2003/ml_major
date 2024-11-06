#include<iostream>
#define N 500050
using namespace std;
int main()
{
   long long int n,cb[N];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&cb[i]);
    }
    string lv;
  long long   int cnt=0,sum=0,da=0,a=0;
    cin>>lv;
    for(int i=0;i<n;i++)
    {
        if(lv[i]=='B')
        {
            cnt+=cb[i];
        }
    }
    da=cnt;
    a=cnt;
    for(int i=0;i<n;i++)
    {
        if(lv[i]=='B')
            cnt-=cb[i];
        else 
        {
            cnt+=cb[i];
        }
            if(cnt>da) da=cnt;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(lv[i]=='B')
            a-=cb[i];
        else 
            a+=cb[i];
        if(a>da)
            da=a;
    }
    printf("%lld",da);
 }
	 				 	    		 	 	 		 	 	 		 	