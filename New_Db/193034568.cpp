#include<iostream>
long long int freq[10];
using namespace std;
int main()
{
    long long int n,i;
    cin>>n;
    long long int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        freq[a[i]]++;
    }
    if(freq[1]==n/3&&freq[3]<=freq[6]&&freq[4]<=freq[2]&&freq[1]==freq[2]+freq[3]&&freq[1]==freq[4]+freq[6])
    {
        for(i=0;i<freq[4];i++)cout<<"1 2 4\n";
        for(i=0;i<freq[3];i++)cout<<"1 3 6\n";
        for(i=0;i<freq[6]-freq[3];i++)cout<<"1 2 6\n";
    }
    else cout<<"-1";
    return 0;
}
