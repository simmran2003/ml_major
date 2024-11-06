#include<bits/stdc++.h>
using namespace std;int main(){int n,m,s,f,d,t{},l,r,c{1},w,W;cin>>n>>m>>s>>f;s<f?d=1,w='R':(d=-1,w='L');
for(;s!=f;){if(c>t)cin>>t>>l>>r||(t=1<<30);
else {W='X';if(c<t||s+d<l|s+d>r&&s<l|s>r)s+=d,W=w;putchar(W);++c;}}}