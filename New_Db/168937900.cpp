#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<vector>
#include<queue>
#include <string>
#include<set>
#include <map>

using namespace std;
typedef long long ll;

const int mx=2e5+5;

int r,h,rest,ans=0;

void init()
{

}


void scan()
{
    cin>>r>>h;
}


void solve()
{
    ans=2*(h/r);
    rest=h%r;
    //cout<<sqrt(3.0)*r/2.0<<endl;
    if(r/2.0*sqrt(3.0)<=(double)rest)
        ans+=3;
    else if((double)rest>=r/2.0)
        ans+=2;
    else ans+=1;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ca=1;
    //cin>>ca;
    while(ca--)
    {
        init();
        scan();
        solve();
    }
	return 0;
}

 			 				 			  			   	   	    	