#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define el endl
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
#define all(x) x.begin(), x.end()
#define sz(v) ((int)((v).size()))
#define vi vector<int>
#define rall(vec) vec.rbegin(), vec.rend()
#define str string
#define rv return void
#define lop(i,n) for(int i=0;i<n;++i)
#define fi first
#define se second
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
str bo[105];
vector<vector<int>>arr(1e5+6);
int nofd (int n)
{
    int cnt=0;
    for(int i=1 ;i*i<=n ; i++)
    {
        if(n%i==0)
        {
            if(n/i==i)cnt++;
            else
                cnt+=2;
        }
    }
    return cnt;
}
/*
 *
 */
void cry() {

    int n , k;
    cin >> n ;
    vector<int>v(n);
    int g_124 =0,g_126=0,g_136=0;
    int arr[7]={0};
    for (int i = 0; i < n ; ++i) {
        cin >> v[i];
        arr[v[i]]++;


    }


    while (arr[1] and arr[2] and arr[4]){
            arr[1]--;
            arr[2]--;
            arr[4]--;
            g_124++;
    }

    while(arr[1] and arr[2] and arr[6])
    {
        arr[1]--;
        arr[2]--;
        arr[6]--;
        g_126++;
    }
    while(arr[1] and arr[3] and arr[6]){
        arr[1] --;
        arr[3]--;
        arr[6]--;
        g_136++;
    }
    if(g_124+g_126+g_136==n/3){
        while (g_136 or g_126 or g_124){
            if(g_126){
                g_126--;
                cout <<"1 2 6\n";
            }
            if(g_136){
                g_136--;
                cout <<"1 3 6\n";
            }
            if(g_124){
                g_124--;
                cout <<"1 2 4\n";
            }
        }
    }else cout <<-1;

}
int main (){
    IO

    int tests = 1;
//    cin >> tests;
    for (int i = 0;  i < tests; ++i) {
        cry();
        cout << "\n";
    }
}