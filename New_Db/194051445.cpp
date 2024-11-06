#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
int gcd(int a,int b);
using namespace std;
int main()
{
    short a;
    cin>>a;
    short b=a;
    short z=0;
    short rem;
    short newa;
    vector<short>h;
    for(short i=2;i<b;i++)
    {
        a=b;
        z++;
        while(a!=0)
        {
        newa=a%i;
        h.push_back(newa);
        a=a/i;
        }
    }
     int sum=0;
    for(short i=0;i<h.size();i++)
    {
        sum=sum+h[i];
    }
    int x= gcd(sum,z);
    cout<<sum/x<<'\/'<<z/x;
}
int gcd(int a,int b)
{
    while(b)
    {
        a=a%b;
        swap(a,b);
    }
    return a;
}

		 		 	   			    		   	      	