#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {
    vector <int> x;
    vector <int> sum;
    int SUM = 0;
    int numerator = 0;
    int demnator = 0;
    int A;
    int B;
    float remainder;
    cin >> A;
    B = A;
    int C;
    for (int  i = 2; i < A ; i++)
    {
        C = B;
        SUM = 0;
        while (C != 0)
        {
            remainder = C%i;
            C=C/i;
            x.push_back(remainder);
        }
        for ( int j = 0; j < x.size(); j++)
        {
            SUM+= x[j];
        }
        sum.push_back(SUM);
        demnator++;
        x.clear();
        
    }
    for (int i = 0; i < sum.size(); i++)
    {
        numerator += sum[i];
    }
    cout << numerator/ gcd(numerator, demnator)  << "/" << demnator/ gcd(numerator, demnator)  << "\n";
    
    
}

	 				   		    	 		 	 		 				 	