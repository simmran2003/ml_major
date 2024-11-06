#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;
int main()
{
  int n,sum,ans,s;
  cin>>n;
  ans =0;
  for(int i=2 ; i<n ; i++)
  {
      s=n;
      sum=0;
      while(s)
      {
        sum+=(s%i);
        s/=i;
      }
      ans+=sum;
  }
  int g=__gcd(ans,n-2);
  cout<<ans/g<<"/"<<(n-2)/g;
}

	  	 						  					  	 	   			