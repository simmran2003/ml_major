
#include <iostream>
#include <cstdint>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void printFraction(int up, int down) {
    for(int i = down <= up? down : up; i > 0; i--) {
        if(up % i == 0 && down % i == 0) {
            cout << up/i << "/" << down/i;
            return;
        }
    }
}


void code() {
    int A;
    cin >> A;
    int denom = A - 2;
    int result = 0;
    for(int i = 2; i < A; i++) {
        int number = A;
        while(number > 0) {
            result += number % i;
            number /= i;
        }
    }

    printFraction(result, denom);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll trials;
    //cin >> trials;
    //for(ll i = 0; i < trials; i++) {
        code();
    //}
}
  		  	 		  	     	   	  		  		