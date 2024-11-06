# include <bits/stdc++.h>
# define ll long long int 
using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll> p(n);
    string s;
    for(ll i=0;i<n;i++)
    {
        cin>>p[i];
    }
    vector<ll> p_a(n,0),p_b(n,0);
    cin>>s;
    for(ll i=0;i<n;i++)
    {
        if(i==0)
        {
            if(s[i]=='A')
            {
                p_a[i]=p[i];
            }
            else
            {
                p_b[i] = p[i];
            }
        }
        else
        {
            if(s[i]=='A')
            {
                p_a[i] =p_a[i-1]+p[i];
                p_b[i] = p_b[i-1];
            }
            else
            {
                p_a[i] =p_a[i-1];
                p_b[i] = p_b[i-1]+p[i];
            }
        }
    }
    ll val=p_b[n-1];
    for(ll i=0;i<n;i++)
    {
        val = max(max(p_a[n-1]-p_a[i]+p_b[i],p_b[n-1]-p_b[i]+p_a[i]),val);
    }
    cout<<val<<endl;
}