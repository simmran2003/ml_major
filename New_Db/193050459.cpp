#include<bits/stdc++.h>
using namespace std;
long long a,h,i,n,p,t;
string s[60];
int32_t main()
{
for(cin>>n>>p;i++<n;)cin>>s[i];
for(;--i;)
{
if(s[i]=="halfplus")h++;
t+=a*p+h*p/2;
a+=a+h;
h=0;
}
cout<<t;
}