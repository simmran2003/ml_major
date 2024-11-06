#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll, ll> ii;
#define eps 1e-9
#define MOD 998244353
#define pi 3.141592653589793
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define yo cout << "I reached here" << endl;
const int INF = 1e9 + 5;

static bool myCompare(string a, string b){
    return a + b < b + a;
}
int main()
{
    int n;
    cin >> n;
    vector<string> V(n);
    for(int i = 0; i < n; i++) cin >> V[i];
    sort(V.begin(), V.end(), myCompare);
    string result = "";
    for(auto x: V) result += x;
    cout << result << endl;
    return 0;
}
