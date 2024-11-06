#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a;
	cin >> a;
	int yt[a+5];
	
	for(int i = 0;i < a;i++)cin>>yt[i];
	long long maxn = 0;
	string s;
	cin >> s;
	for(int i = 0;i < a;i++)
	{
		if(s[i] == 'B')maxn += yt[i];
	}
	long long  mina = maxn;
	long long z = maxn;
	for(int i = 0;i < a;i++)
	{
		if(s[i] == 'B')mina -=  yt[i];
		else mina += yt[i];
		maxn = max(mina,maxn);
	}
	mina = z;
	for(int i = a - 1;i >= 0;i--)
	{
		if(s[i] == 'B')mina -= yt[i];
		else mina += yt[i];
		maxn = max(mina,maxn);
	}
	cout << maxn;
}
 			  	    	  	 			  	 	 			