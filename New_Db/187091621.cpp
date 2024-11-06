// LUOGU_RID: 98192597
#include<bits/stdc++.h>
using namespace std;
int read() {
	int x = 0,f = 0;char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = 1;ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0';ch = getchar();}
	return f ? -x : x;
}
const int N = 2510;
struct Node{int x,y,val;}s[N*N];
bitset<N> f[N];
bool cmp(Node a,Node b) {return a.val < b.val;}
int n,id = 0,val[N][N];
int main() {
	n = read();
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) val[i][j] = read();
		if(val[i][i]) {printf("NOT MAGIC\n");return 0;}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			s[++id].x = i;s[id].y = j;s[id].val = val[i][j];
			if(val[i][j] != val[j][i]) {printf("NOT MAGIC\n");return 0;}
		}		
	}
	sort(s+1,s+1+id,cmp);
	for(int l = 1,r = 0;l <= id;) {
		r = l;
		while(r < id && s[r].val == s[r+1].val) r++;
		for(int j = l;j <= r;j++) {
			if((f[s[j].x] & f[s[j].y]).any()) {printf("NOT MAGIC\n");return 0;}
		}
		for(int j = l;j <= r;j++) f[s[j].x][s[j].y] = 1;
		l = r + 1;
	}
	printf("MAGIC\n");
	return 0;
}
