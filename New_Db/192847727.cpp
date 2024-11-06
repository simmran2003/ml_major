#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;
const int Z=10;
const int Mod=998244353;
const int G=3;
const int INV2=(Mod+1)/2;
inline int Read(){
    char ch;
    int f=1;
    while((ch=getchar())<'0'||ch>'9')
        if(ch=='-') f=-1;
    int x=ch^48;
    while((ch=getchar())>='0'&&ch<='9')
        x=(x<<3)+(x<<1)+(ch^48);
    return x*f;
}
inline void print(int x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(int x,char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline int Quick_Pow(int a,int b){
    int ss=1;
    for(;b;b>>=1){
        if(b&1) ss=1ll*ss*a%Mod;
        a=1ll*a*a%Mod;
    }
    return ss;
}
inline void Swap(int&x,int&y){
    int tmp=x;
    x=y;y=tmp;
    return ;
}
int rev[N<<3];
inline void NTT(int*p,int s1,bool inv){
    for(int i=0;i<s1;i++)
        if(i<rev[i]) Swap(p[i],p[rev[i]]);
    for(int mid=1;mid<s1;mid<<=1){
        int wn=Quick_Pow(G,(Mod-1)/(mid<<1));
        if(inv) wn=Quick_Pow(wn,Mod-2);
        for(int len=mid<<1,i=0;i<s1;i+=len){
            int w=1;
            for(int j=0;j<mid;j++,w=1ll*w*wn%Mod){
                int a1=p[i+j],a2=p[i+j+mid];
                p[i+j]=(a1+1ll*w*a2%Mod)%Mod;
                p[i+j+mid]=(a1-1ll*w*a2%Mod+Mod)%Mod;
            }
        }
    }
    return ;
}
inline void GetMul(int*f,int*g,int n,int m,int*p){
    int s1=1,pos=0;
    while(s1<=(n+m)) s1<<=1,pos++;
    for(int i=0;i<s1;i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(pos-1));
    NTT(f,s1,0);NTT(g,s1,0);
    for(int i=0;i<s1;i++)
        p[i]=1ll*f[i]*g[i]%Mod;
    NTT(f,s1,1);NTT(g,s1,1);NTT(p,s1,1);
    int inv=Quick_Pow(s1,Mod-2);
    for(int i=0;i<s1;i++){
        f[i]=1ll*f[i]*inv%Mod;
        g[i]=1ll*g[i]*inv%Mod;
        p[i]=1ll*p[i]*inv%Mod;
    }
    return ;
}
inline void GetDao(int*f,int*g,int n){
    for(int i=0;i<n-1;i++)
        g[i]=1ll*(i+1)*f[i+1]%Mod;
    return ;
}
inline void GetJi(int*f,int*g,int n){
    for(int i=1;i<=n;i++)
        g[i]=1ll*f[i-1]*Quick_Pow(i,Mod-2)%Mod;
    return ;
}
inline void GetInv(int*f,int*g,int n){
    static int gp[N<<3],tmp[N<<3];
    g[0]=Quick_Pow(f[0],Mod-2);
    for(int len=1,t=0;len<n;len<<=1,t++){
        int s1=len<<1,pos=t+1;
        for(int i=0;i<s1;i++){
            gp[i]=g[i];
            tmp[i]=f[i];
        }
        s1<<=1,pos++;
        for(int i=len<<1;i<s1;i++)
            gp[i]=tmp[i]=0;
        for(int i=0;i<s1;i++)
            rev[i]=(rev[i>>1]>>1)|((i&1)<<(pos-1));
        NTT(gp,s1,0);NTT(tmp,s1,0);
        for(int i=0;i<s1;i++){
            g[i]=2*gp[i]%Mod;
            int gl=1ll*gp[i]*gp[i]%Mod*tmp[i]%Mod;
            g[i]=(g[i]-gl+Mod)%Mod;
        }
        NTT(g,s1,1);
        int inv=Quick_Pow(s1,Mod-2);
        for(int i=0;i<s1;i++)
            g[i]=1ll*g[i]*inv%Mod;
        for(int i=len<<1;i<s1;i++)
            g[i]=0;
    }
    return ;
}
inline void GetLn(int*f,int*g,int n){
    static int finv[N<<3],fdao[N<<3],gdao[N<<3];
    GetDao(f,fdao,n);
    GetInv(f,finv,n);
    int s1=1,pos=0;
    while(s1<=(n<<1)) s1<<=1,pos++;
    for(int i=n;i<s1;i++)
        fdao[i]=finv[i]=0;
    for(int i=0;i<s1;i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(pos-1));
    NTT(fdao,s1,0);NTT(finv,s1,0);
    for(int i=0;i<s1;i++)
        gdao[i]=1ll*fdao[i]*finv[i]%Mod;
    NTT(gdao,s1,1);
    int inv=Quick_Pow(s1,Mod-2);
    for(int i=0;i<s1;i++)
        gdao[i]=1ll*gdao[i]*inv%Mod;
    GetJi(gdao,g,n);
    return ;
}
inline void GetExp(int*f,int*g,int n){
    static int gp[N<<3],gpln[N<<3],tmp[N<<3];
    g[0]=1;
    for(int len=1,t=0;len<(n<<1);len<<=1,t++){
        int s1=len<<1,pos=t+1;
        for(int i=0;i<s1;i++){
            gp[i]=g[i];
            tmp[i]=f[i];
            gpln[i]=0;
        }
        GetLn(gp,gpln,len);
        s1<<=1,pos++;
        for(int i=len<<1;i<s1;i++)
            gp[i]=tmp[i]=gpln[i]=0;
        for(int i=0;i<s1;i++)
            rev[i]=(rev[i>>1]>>1)|((i&1)<<(pos-1));
        NTT(gp,s1,0);NTT(gpln,s1,0);NTT(tmp,s1,0);
        for(int i=0;i<s1;i++){
            int gl=(gpln[i]-tmp[i]+Mod)%Mod;
            g[i]=(gp[i]-1ll*gl*gp[i]%Mod+Mod)%Mod;
        }
        NTT(g,s1,1);
        int inv=Quick_Pow(s1,Mod-2);
        for(int i=0;i<s1;i++)
            g[i]=1ll*g[i]*inv%Mod;
        for(int i=len<<1;i<s1;i++)
            g[i]=0;
    }
    return ;
}
inline void GetSqr(int*f,int*g,int n){
    static int gp[N<<3],gpinv[N<<3],tmp[N<<3];
    g[0]=1;
    for(int len=1,t=0;len<(n<<1);len<<=1,t++){
        int s1=len<<1,pos=t+1;
        for(int i=0;i<s1;i++){
            gp[i]=g[i];
            tmp[i]=f[i];
        }
        GetInv(gp,gpinv,len);
        s1<<=1,pos++;
        for(int i=len<<1;i<s1;i++)
            gp[i]=tmp[i]=gpinv[i]=0;
        for(int i=0;i<s1;i++)
            rev[i]=(rev[i>>1]>>1)|((i&1)<<(pos-1));
        NTT(gp,s1,0);NTT(tmp,s1,0);NTT(gpinv,s1,0);
        for(int i=0;i<s1;i++){
            g[i]=(tmp[i]+1ll*gp[i]*gp[i]%Mod)%Mod;
            g[i]=1ll*g[i]*INV2%Mod*gpinv[i]%Mod;
        }
        NTT(g,s1,1);
        int inv=Quick_Pow(s1,Mod-2);
        for(int i=0;i<s1;i++)
            g[i]=1ll*g[i]*inv%Mod;
        for(int i=len<<1;i<s1;i++)
            g[i]=0;
    }
    return ;
}
inline void GetPow(int*f,int*g,int n,int k){
    static int fln[N<<3];
    GetLn(f,fln,n);
    for(int i=0;i<n;i++)
        fln[i]=1ll*fln[i]*k%Mod;
    GetExp(fln,g,n);
    return ;
}
inline void GetDiv(int*A,int*B,int*f,int n,int m){
    static int Binv[N<<3];
    reverse(A,A+n+1);
    reverse(B,B+m+1);
    GetInv(B,Binv,n-m+1);
    int s1=1,pos=0;
    while(s1<=(2*n-m+2)) s1<<=1,pos++;
    for(int i=n-m+1;i<s1;i++)
        Binv[i]=0;
    for(int i=0;i<s1;i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(pos-1));
    NTT(A,s1,0);NTT(Binv,s1,0);
    for(int i=0;i<s1;i++)
        f[i]=1ll*A[i]*Binv[i]%Mod;
    NTT(A,s1,1);NTT(f,s1,1);
    int inv=Quick_Pow(s1,Mod-2);
    for(int i=0;i<s1;i++){
        A[i]=1ll*A[i]*inv%Mod;
        f[i]=1ll*f[i]*inv%Mod;
    }
    reverse(A,A+n+1);
    reverse(B,B+m+1);
    reverse(f,f+n-m+1);
    return ;
}
inline void GetMod(int*A,int*B,int*g,int n,int m){
    static int f[N<<3];
    GetDiv(A,B,f,n,m);
    int s1=1,pos=0;
    while(s1<=(n+2)) s1<<=1,pos++;
    for(int i=0;i<s1;i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(pos-1));
    NTT(A,s1,0);NTT(B,s1,0);NTT(f,s1,0);
    for(int i=0;i<s1;i++)
        g[i]=(A[i]-1ll*B[i]*f[i]%Mod+Mod)%Mod;
    NTT(A,s1,0);NTT(B,s1,0);NTT(g,s1,1);
    int inv=Quick_Pow(s1,Mod-2);
    for(int i=0;i<s1;i++){
        A[i]=1ll*A[i]*inv%Mod;
        B[i]=1ll*B[i]*inv%Mod;
        g[i]=1ll*g[i]*inv%Mod;
    }
    return ;
}
int n,k;
int f[Z][N<<1],g[N<<1],g1[N<<1];
int len[Z],nowlen;
inline int Max(int x,int y){
	return x>y?x:y;
}
inline int Min(int x,int y){
	return x<y?x:y;
}
inline void Cmax(int&x,int y){
	if(y>x) x=y;
	return ;
}
inline void Cmin(int&x,int y){
	if(y<x) x=y;
	return ;
}
inline void Init(){
	n=Read(),k=Read();
	for(int i=1;i<=n;i++){
		int x=Read();
		f[0][x]=1;
		Cmax(len[0],x+1);
	}
	return ;
}
inline void Solve(){
	for(int i=1;i<Z;i++){
		memcpy(g,f[i-1],sizeof(g));
		GetMul(f[i-1],g,len[i-1],len[i-1],f[i]);
		len[i]=len[i-1]+len[i-1]-1;
	}
	memset(g,0,sizeof(g));
	nowlen=1;g[0]=1;
	for(int i=0;i<Z;i++)
		if(k&(1<<i)){
			memcpy(g1,g,sizeof(g1));
			GetMul(f[i],g1,len[i],nowlen,g);
			nowlen+=len[i]-1;
			for(int j=0;j<nowlen;j++)
				g[j]=(g[j]>0);
		}
	for(int i=1;i<nowlen;i++)
		if(g[i]) Print(i,' ');
	putchar('\n');
}
#include<ctime>
int main(){
	//#define LOCAL
	#ifdef LOCAL
	int st=clock();
	#endif
	Init();
	Solve();
	#ifdef LOCAL
	int en=clock();
	printf("cost %d ms\n",en-st);
	#endif
	return 0;
}
  				 	 	 	    	 	  			 	    	