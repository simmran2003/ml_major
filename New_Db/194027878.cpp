#include<bits/stdc++.h>
using namespace std;
int GCD(int m, int n)
{
    int r = m % n;
    while (r != 0)
    {
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}

int main()
{
    int a;
    cin>>a;

    int X=0, Y=a-2;
    for (int i = 2; i < a; ++i)
    {
        int n=a, partofsum=0;
        while (n != 0)
        {
            partofsum += n % i;
            n /= i;
        }
        X += partofsum;
    }

    int gcd = GCD(X, Y);
    X /= gcd;
    Y /= gcd;
    printf("%d/%d\n", X, Y);
    return 0;
}
	 	  								  									 		   	