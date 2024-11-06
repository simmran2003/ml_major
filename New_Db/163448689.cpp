#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
string s1,s2,s3;
int n;
bool ok[8][8]={
0,1,0,0,1,0,0,1,
1,0,0,0,0,0,1,0,
0,0,0,0,0,1,0,0,
0,0,0,0,1,0,0,0,
1,0,0,1,0,0,0,0,
0,0,1,0,0,0,0,0,
0,1,0,0,0,0,0,0,
1,0,0,0,0,0,0,0
};
int operate(){
	int dp[n+1][8];
	for(int i=0;i<=n;i++) for(int j=0;j<8;j++) dp[i][j]=0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<8;j++){
			for(int k=0;k<8;k++){
				int a1=j&1,a2=(j>>1)&1,a3=(j>>2)&1,nj=j;
				int b1=k&1,b2=(k>>1)&1,b3=(k>>2)&1;
//				cout<<k<<" "<<a1<<" "<<a2<<" "<<a3<<" "<<s1[i]<<" "<<s2[i]<<" "<<s3[i]<<endl;
				if(s1[i]=='X'&&a1) continue; else if(s1[i]=='X') nj++;
				if(s2[i]=='X'&&a2) continue; else if(s2[i]=='X') nj+=2;
				if(s3[i]=='X'&&a3) continue; else if(s3[i]=='X') nj+=4;
//				if(nj==0) cout<<ok[nj][k]<<" ";
				if(ok[nj][k]){
//					cout<<j<<" "<<nj<<" "<<k<<endl;
					dp[i][k]=(dp[i][k]+dp[i-1][j])%mod;
				}
			}
		}
//		for(int j=0;j<8;j++) cout<<dp[i][j]<<" ";
//		cout<<endl;
	} 
//	cout<<endl;
	return dp[n][0];
}
signed main(){
	cin>>n>>s1>>s2>>s3;
	s1=" "+s1,s2=" "+s2,s3=" "+s3;
	int x,y;
	int can[4];
	can[0]=can[1]=can[2]=can[3]=1;
	for(int i=1;i<=n;i++) if(s1[i]=='O'){
		x=1,y=i,s1[i]='X';
		can[2]=0;		
		if(s3[y]=='X'||s2[y]=='X') can[3]=0;
		if(y<3) can[0]=0;
		else if(s1[y-1]=='X'||s1[y-2]=='X') can[0]=0;
		if(y>n-2) can[1]=0;
		else if(s1[y+1]=='X'||s1[y+2]=='X') can[1]=0;
	}
	for(int i=1;i<=n;i++) if(s2[i]=='O'){
		x=2,y=i,s2[i]='X';
		can[2]=can[3]=0;
		if(y<3) can[0]=0;
		else if(s2[y-1]=='X'||s2[y-2]=='X') can[0]=0;
		if(y>n-2) can[1]=0;
		else if(s2[y+1]=='X'||s2[y+2]=='X') can[1]=0;
	}
	for(int i=1;i<=n;i++) if(s3[i]=='O'){
		x=3,y=i,s3[i]='X';
		can[3]=0;
		if(s1[y]=='X'||s2[y]=='X') can[2]=0;
		if(y<3) can[0]=0;
		else if(s3[y-1]=='X'||s3[y-2]=='X') can[0]=0;
		if(y>n-2) can[1]=0;
		else if(s3[y+1]=='X'||s3[y+2]=='X') can[1]=0;
	}
//	cout<<x<<" "<<y<<" "<<s1<<" "<<s2<<" "<<s3<<" "<<s1[1]<<" "<<s2[1]<<" "<<s3[1]<<endl;
	int ans=0;
	for(int i=1;i<(1<<4);i++){
		int ok=1,t=i,rp[4];
		for(int j=0;j<4;j++){
			if(t%2==1&&can[j]==0) ok=0;
			rp[j]=t&1;
			t>>=1;
		}
		if(!ok) continue;
		if(rp[0]){
			if(x==1) s1[y-1]='X',s1[y-2]='X';
			if(x==2) s2[y-1]='X',s2[y-2]='X';
			if(x==3) s3[y-1]='X',s3[y-2]='X';
		}
		if(rp[1]){
			if(x==1) s1[y+1]='X',s1[y+2]='X';
			if(x==2) s2[y+1]='X',s2[y+2]='X';
			if(x==3) s3[y+1]='X',s3[y+2]='X';
		}
		if(rp[2]){
			s1[y]=s2[y]='X';
		}
		if(rp[3]){
			s3[y]=s2[y]='X';
		}
		if(__builtin_popcount(i)%2==1) ans=(ans+operate())%mod;
		else ans=(ans+mod-operate())%mod;
		if(rp[0]){
			if(x==1) s1[y-1]='O',s1[y-2]='O';
			if(x==2) s2[y-1]='O',s2[y-2]='O';
			if(x==3) s3[y-1]='O',s3[y-2]='O';
		}
		if(rp[1]){
			if(x==1) s1[y+1]='O',s1[y+2]='O';
			if(x==2) s2[y+1]='O',s2[y+2]='O';
			if(x==3) s3[y+1]='O',s3[y+2]='O';
		}
		if(rp[2]){
			s1[y]=s2[y]='O';
		}
		if(rp[3]){
			s3[y]=s2[y]='O';
		}
	}
	cout<<ans;
} 