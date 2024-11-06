#include <bits/stdc++.h>
//#include <string>
#include <algorithm>
//#include <vector>
//#include <set>
#include <numeric>
#define ll long long
using namespace std;
const int k = 1e5*2;
int arr[k];

int main() {

    int a;
    cin >> a;
    int sum = 0;
    for (int i = 2; i < a; i++) {
        int x = a;
        while (x) {
            sum += x % i;
            x /= i;
        }
    }
    int y = gcd(sum , a-2);
    cout<< sum/y << "/"<< (a-2)/y;
}
	  			  	 	  	 		  	 	 	 	  			