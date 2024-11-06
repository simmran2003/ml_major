#include <bits/stdc++.h>
#include<string>
#include<vector>
#define ll long long int
#define L "\n"
#define fixed(n) fixed << setprecision(n);
constexpr int Mod = 1e9 + 7;
#define inf 1000000000000000005
#define rall(vec) vec.rbegin(),vec.rend()
#define all(v) v.begin(), v.end()
#define cin(v) for (auto&i:v) cin >> i;
#include <math.h>
using namespace std;
typedef vector<int> vi;
typedef vector<ll> vll;
void fast () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}void fast2 () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
typedef pair<int,int> pii;
int powExponentiation(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n%2==1){result=result*x;}
        x=x*x;
        n=n/2;
    }
    return result;
}
int binarySearch(ll arr[],ll left,ll right,ll search){
    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid] == search){
            return mid;
        } else if (arr[mid] < search){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
//// Recursion
int factorial(ll n){
    ////base case .... alle you arafha
    if(!n)return 1;//n==1
    //// transition .... almafrod mch yadu al base
    return (n* (factorial(n-1)));
}
int fib(int n){
    ////base case
    if(n<2)return n;
    //// transition
    return fib(n-1)+ fib(n-2);
}

//ll const Mod=((1e9) + 7);
int freq[1000000];

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
bool prime(int n) {
if(n==2)return true;

    if(n<2||n%2==0)return false;

    for (int i = 3; i *i<= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}


struct grades{
    int a,m,s,e;
    string name;
    ll sum;
};
//int i=0;
//bool ch(string a,string b){
//    if(a[i]!=b[i]){
//        return min(a[i],b[i]);
//    }
//    return ch(a[i++],b[i++]);
//}
//bool cmp(string a,string b){
//    if(a.size()==b.size()){
//        return (a<b);
//    }
//
//        for (int i = 0; i < max(a.size(),b.size()); ++i) {
//                if(a[i]>b[i]){
//                    return a>b;
//                }else if(a[i]<b[i]){
//                    return a<b;
//                }
//            if(i== min(a.size(),b.size())-1){
//                return min(a.size(),b.size())<max(a.size(),b.size());
//            }
//        }
//
//}
bool cmp(string a,string b){
    return a+b<b+a;
}
int main() {
    fast();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
  int n;
  cin>>n;
    vector<string>q;
    string s;while(n--){
        cin>>s;
        q.push_back(s);
    }
    sort(all(q),cmp);
    for (auto i:q) {
        cout << i;

    }

    return 0;}