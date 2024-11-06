#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
typedef long long ll;
typedef double db;
using namespace std;
inline int read(){
	register int x=0,f=0,ch=getchar();
	while('0'>ch||ch>'9')f^=ch=='-',ch=getchar();
	while('0'<=ch&&ch<='9')x=x*10+(ch^'0'),ch=getchar();
	return f?-x:x;
}
const int P = 1e9+7;
const int MAX=1e4+5;
int n;string s[4];
struct node{int x,y,xx,yy;}E[MAX];
int T=0;
int lin[4][MAX],f[MAX][8];
inline int check(int x,int y){
	if(x<1 ||x>3 || y<1 ||y>n ||lin[x][y]) return 0;
	return 1;
} 
inline int add(int x,int y){
	x+=y;
	return x>=P?x-P:x;
}
inline int dp(){
	memset(f,0,sizeof(f));
	f[0][7] = 1;
	for(register int i=1;i<=n;++i){
		int T=0;
		if(!check(1,i))T|=1;
		if(!check(2,i))T|=2;
		if(!check(3,i))T|=4;
	/*	0 000
		1 001
		2 010
		3 011
		4 100
		5 101
		6 110
		7 111	*/
		for(register int S=0;S<8;++S){
			if(S & T)continue;
			f[i][S|T] = add(f[i-1][7-S],f[i][S|T]);
			if(S==7) f[i][S|T] = add(f[i][S|T],add(f[i-1][3],f[i-1][6]));
			if(S==3 || S==6) f[i][S|T] = add(f[i][S|T],f[i-1][7]);
		}
	}
	return f[n][7];
}
signed main(){
	n=read();
	for(register int j=1;j<=3;++j){
		cin>>s[j],s[j]= ' '+s[j];
		for(register int i=1;i<=n;++i)
			if(s[j][i] == 'O' || s[j][i] == 'X')lin[j][i] = 1;
	}
	for(register int i=1;i<=3;++i){
		for(register int j=1;j<=n;++j){
			if(s[i][j] == 'O'){
				if(check(i,j+1) && check(i,j+2))E[++T] = (node){i,j+1,i,j+2};
				if(check(i,j-1) && check(i,j-2))E[++T] = (node){i,j-1,i,j-2};
				if(check(i+1,j) && check(i+2,j))E[++T] = (node){i+1,j,i+2,j};
				if(check(i-1,j) && check(i-2,j))E[++T] = (node){i-1,j,i-2,j};
			}
		}
	}
	
//	for(register int i=1;i<=T;++i){
//		printf("%d %d %d %d\n",E[i].x,E[i].y,E[i].xx,E[i].yy);
//	}
	int ans=0;
	for(register int S=1;S<(1<<T);++S){
		int popc=0;
		for(register int i=1;i<=T;++i){
			if(S>>(i-1)&1){
				lin[E[i].x][E[i].y] = 1;
				lin[E[i].xx][E[i].yy] = 1; 
				++popc;
			}
		}
		int ret = dp();
//		printf("%d\n",ret);
		
		if(popc & 1) ans = add(ans,ret); 
		else ans = add(ans,(P-ret)%P);
		
		for(register int i=1;i<=T;++i){
			if(S>>(i-1)&1){
				lin[E[i].x][E[i].y] = 0;
				lin[E[i].xx][E[i].yy] = 0; 
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
