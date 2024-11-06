#include <bits/stdc++.h>
#define fr(i,a,n)        for (long long i=a;i<n;i++)

using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    ll n,n1=0,n2=0,n3=0,n4=0,n6=0;
    bool flag=0;
    cin>>n;
    ll a[n];
    fr(i,1,n+1)
    {
        cin>>a[i];
        if (a[i]==1)
            n1++;
        else if (a[i]==2)
            n2++;
        else if (a[i]==3)
            n3++;
        else if (a[i]==4)
            n4++;
        else if (a[i]==6)
            n6++;
    }
    ll k=n/3;
    if (n1+n2+n3+n4+n6<n||n1<k||n2+n3<k||n4+n6<k||n2+n3!=n4+n6)
        cout<<-1;
    else if (n3==0&&n2<n4+n6)
        cout<<-1;
    else if (n2==0&&n4!=0)
        cout<<-1;
    else if (n2==0&&n3<n6)
        cout<<-1;
    else if (n2<n4||n6<n3)
        cout<<-1;
    else
        while (k--)
        {
            cout<<1<<" ";
            n1--;
            if (n2!=0)
            {
                cout<<2<<" ";
                n2--;
            }
            else
            {
                cout<<3<<" ";
                n3--;
            }
            if (n4!=0)
            {
                cout<<4<<" ";
                n4--;
            }
            else
            {
                cout<<6<<" ";
                n6--;
            }
            cout<<"\n";
        }
    return 0;
}