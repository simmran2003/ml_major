
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector> 
#include<string>
#include<map>
//#include <bits/stdc++.h>

using namespace std;
#define FAST ios_base::sync_with_stdio(0),cin.tie(0)
typedef long long ll;
const int N = 2e5 + 9, M = 2e5 + 6, MOD = 998244353, OO = 0x3f3f3f3f, SQR = 320;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int main() {
    FAST;
	int n , count , x,sum =0 ; cin >> n; 
	count = n - 2;
	for (int i = 2; i < n; i++) {
		int temp = n; 
		while (temp > 0) {
			int x = temp % i; 
			temp = temp / i;
			sum += x; 

		}
	}
	x = gcd(sum, count);
	cout << sum / x << '/' << count / x << endl; 
}
  		 	 	 		 	  	  		    	 	 	 	