#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int Maxn=1e4,Mod=1e9+7;

int n,ans; char s[3][Maxn+5];
int f[Maxn+5][8];
vector<array<int,4>> v;

inline void add(int &x,int y) {x=(x+y)%Mod;}
inline void Set(array<int,4> x,char y) {s[x[0]][x[1]]=y,s[x[2]][x[3]]=y;}
inline int Solve()
{
    // For(i,0,2)
    // {
    //     For(j,1,n) putchar(s[i][j]);
    //     putchar('\n');
    // }
    memset(f,0,sizeof(f)); f[0][7]=1;
    For(i,1,n)
    {
        int op=0;
        For(j,0,2) if(s[j][i]!='.') op|=(1<<j);
        For(j,0,7) if(f[i-1][j])
        {
            int k=(j^7);
            if(k&op) continue;
            add(f[i][k|op],f[i-1][j]);
            if(!(k&3) && !(3&op)) add(f[i][k|3|op],f[i-1][j]);
            if(!(k&6) && !(6&op)) add(f[i][k|6|op],f[i-1][j]);
        }
    }
    return f[n][7];
}
inline void Count()
{
    int siz=v.size(),lim=(1<<siz)-1;
    For(i,1,lim)
    {
        int pop=__builtin_popcount(i);
        For(j,0,siz-1) if(i&(1<<j)) Set(v[j],'X');
        int res=Solve();
        if(pop&1) ans=(ans+res)%Mod;
        else ans=(ans-res+Mod)%Mod;
        For(j,0,siz-1) if(i&(1<<j)) Set(v[j],'.');
    }
}

int main()
{
    // freopen("1.in","r",stdin);

    scanf("%d",&n);
    For(i,0,2) scanf("%s",s[i]+1);
    int x,y;
    For(i,0,2) For(j,1,n) if(s[i][j]=='O') x=i,y=j;
    if(x==2 && s[0][y]=='.' && s[1][y]=='.') v.push_back({0,y,1,y});
    if(x==0 && s[1][y]=='.' && s[2][y]=='.') v.push_back({1,y,2,y});
    if(y>=3 && s[x][y-2]=='.' && s[x][y-1]=='.') v.push_back({x,y-2,x,y-1});
    if(y+2<=n && s[x][y+1]=='.' && s[x][y+2]=='.') v.push_back({x,y+1,x,y+2});
    Count();
    printf("%d\n",ans);
    return 0;
}