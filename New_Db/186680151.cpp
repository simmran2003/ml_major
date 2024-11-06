#include<bits/stdc++.h>
using namespace std;
long double pi = 3.14159265358979323846;
int main(){
    long long r,h;
    cin>>r>>h;
    long long m = h/r;
    long long sl = r + h - m*r;
    long double sft = (long double)r*(1.0 + sin(pi/3.0));
    long double sftw = (long double)r*1.5;
    // cout<<"Space Occupied = " << m<<endl;
    // cout<<"Space Left = "<< sl<<endl;
    // cout<<"Space for Three = " << sft<<endl;
    // cout<<"Space for Two =" <<sftw<<endl;
    if((long double)sl >= sft){
        cout<< 3 + 2*m;
    }
    else if((long double)sl >= sftw){
        cout<< 2 + 2*m;
    }
    else if((long double)sl >= r){
        cout<< 1 + 2*m;
    }
    else{
        cout<<2*m;
    }


}