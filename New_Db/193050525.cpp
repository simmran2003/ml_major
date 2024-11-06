#include<bits/stdc++.h>
#define N 100010
#define B 350
using namespace std;
int n,q,a[N],las[N],cnt[N];
void get(int i){
if(i+a[i]>=n||i/B!=(i+a[i])/B)las[i]=i,cnt[i]=0;
else las[i]=las[i+a[i]],cnt[i]=cnt[i+a[i]]+1;
}
int main(){
scanf("%d%d",&n,&q);
for(int i=0;i<n;++i)cin>>a[i];
for(int i=n-1;i>=0;--i)get(i);
for(int o,p,v;q--;){
scanf("%d",&o);
if(o){
scanf("%d",&p);--p;
int dwn=0,s=0;
for (;p<n;dwn=las[p],p=dwn+a[dwn]) s+=cnt[p]+1;
printf("%d %d\n",dwn+1,s);
}
else{
scanf("%d%d",&p,&v);--p;a[p]=v;
for(int i=p;i>=0&&i/B==p/B;--i)get(i);
}
}
return 0;
}