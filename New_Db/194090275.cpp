#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
#define rep(i,x,n) for(int i=x;i<n;++i) 
#define rev(i,x,n) for(int i=n-1;i>=x;--i) 
#define v(num) v.push_back(num) 
#define ll long long 
#define int(n) int n; cin>>n 


int main(){
    IOS;

    int n;
    cin>>n;

    int arr[n];
    int c0(0),c1(0),c2(0),c3(0),c4(0),c6(0);

    rep(i,0,n) {
        cin>>arr[i];
    
        if(arr[i] == 1) c1++;
        else if(arr[i] == 2) c2++;
        else if(arr[i] == 3) c3++;
        else if(arr[i] == 4) c4++;
        else if(arr[i] == 6) c6++;
        else c0++;
    }

    bool f=0;

    if(c0>0 || c1 != n/3 || c2+c3 != c4+c6 || c4>c2) f=1;

    if(f) cout<<-1;
    else{
        
        c2 -= c4;
        while(c4--){
            cout<<"1 2 4"<<endl;
        }

        c6 -= c3;
        while(c3--){
            cout<<"1 3 6"<<endl;
        }

        while(c6--){
            cout<<"1 2 6\n";
        }

    }






    return 0;
}