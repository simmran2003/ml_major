#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if(b==0){
        return a;
    }
    else{
        return gcd(b, a % b);
    }
}
int main(){
    int a;
    int tmp;
    int sum;
    int n = 0;
    cin >> a;
    int d = a - 2;
    
    vector<int> base;
    vector<int> sums;
    for (int i = 2; i < a; i++) {
        tmp = a;
        sum = 0;
        while (tmp > 0) {
            base.push_back(tmp % i);
            tmp = tmp / i;
        }
        for (int j = 0; j < base.size(); j++) {
            sum += base[j];
        }
        sums.push_back(sum);
        base.clear();
    }
    for (int k = 0; k < sums.size(); k++) {
        n += sums[k];
    }
    int g = gcd(n,d);
    n = n /g;
    d = d /g;
    cout << n << "/" << d;

    return 0;
}

						 		 		  	  		  	     			