#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define el "\n"
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

const ll N=1e4+5;
const ll mod=1e9+7;
int dx[]={0,-1,0,1,-1,1,-1,1};
int dy[]={-1,0,1,0,1,-1,-1,1};
ll n,m,k,y,x;
int dp[N][10][2];
int unvalid[N];
int add(int a,int b)
{
    return (a+1LL*b)%mod;
}
bool mnwr(int bit,int mask)
{
    if ((1<<bit)&mask)
    {
        return 1;
    }
    return 0;
}
int solve(int i,int msk,int move)
{
    if (i==n)
    {
        if (msk==0&&move)
        {
            return 1;
        }
        return 0;
    }
    int &ans=dp[i][msk][move];
    if (~ans)
    {
        return ans;
    }
    ans=0;
    for(int j=0;j<3;j++)
    {
        if(mnwr(j,msk)&&mnwr(j,unvalid[i]))
        {
            return ans=0;
        }
        else if(mnwr(j,unvalid[i]))
        {
            msk|=(1<<j);
        }
    }
    bool nm=move;
    for(int j=0;j<3;j++)
    {
        nm|=(mnwr(j,msk)&&!mnwr(j,unvalid[i])&&x==j&&(y==i+1||y==i-2));
    }
    ans=solve(i+1,msk^7,nm);
    if((msk&3)==0)
    {
        ans=add(ans,solve(i+1,(msk|3)^7,nm|(x==2&&y==i)));
    }
    if((msk&6)==0)
    {
        ans=add(ans,solve(i+1,(msk|6)^7,nm|(x==0&&y==i)));
    }
    return ans;
}
void dowork()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    string s;
    for (int i=0;i<3;i++)
    {
        cin>>s;
        for (int j=0;j<n;j++)
        {
            if(s[j]=='O')
            {
                x=i;
                y=j;
            }
            if(s[j]!='.')
            {
                unvalid[j]|=(1<<i);
            }
        }
    }
    cout<<solve(0,0,0)<<el;
}
int main()
{
    fast
    //freopen("zone.in","r",stdin);
    //freopen("standard output","w",stdout);
    int t=1;
    //cin>>t;
    for (int i=1;i<=t;i++)
    {
        dowork();
    }
}