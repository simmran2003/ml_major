#include <bits/stdc++.h>
using namespace std;
int i,n;
string m[50005];
bool f(string a, string b){
return a+b<b+a;
}
int main(){
cin>>n;
for(i=0;i<n;i++){
cin>>m[i];
}
sort(m,m+n,f);
for(i=0;i<n;i++){
cout<<m[i];
}
}