#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x = 0;
    cin >> n;
    int j = n - 2;
    for(int i = 2;i < n;i++)
    {
        int y = n;
        while(y > 0)
        {
            x += y % i,y /= i;
        }
    }
    for(int i = 2;i * i < x;i++) while(j % i == 0&&x % i == 0) j /= i,x /= i;
    cout << x << "/" << j;
    return 0;
}
	   	  			    			   	 				   		