#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int jinzhi(int n,int i) 
{
	int k=n,temp=0,sum=0;
	while(k>0)
	{
		sum=sum+k%i;
		k=k/i;
	}
	return sum;
}
int gys(int n,int m)
{
	if(n%m==0) return m;
	return gys(m,n%m);
}
int main()
{
	int i,j,k,n,m,sum=0,p;
	cin>>n;
	for(i=2;i<=n-1;i++) sum=sum+jinzhi(n,i);
	n=n-2;
	if(sum<n) swap(sum,n);
	p=gys(sum,n);
	sum=sum/p;
	n=n/p;
	cout<<sum<<"/"<<n;
	return 0;
}


 			    	 			 			 	 	    		