#include <bits/stdc++.h>
using namespace std;

int main() {
    long double r,h ,x,y;
    long long n,m,k;
    cin>> r>>h;
    x = 2*floor(h/r);
    y=2*ceil(h/r);
    if(h+r-r*(y/2)>= r*sqrt(3)/2&& h>r){
        y=y+1;
    }else{
        y=0;
}
 
    k=y;

    n=x+1;
    m=x+2;
    if(h>=r){
    if(h-r*(x/2)>=r/2){
        cout<<max(m,k);
    }else{
        cout<<max(n,k);
    }
    }else{
        if(h>=r*sqrt(3)/2){cout<<"3";}
        else if(h>=r/2){ cout<<"2";
        }else{cout<<"1";}
    }
}