#include <bits/stdc++.h>
#define N 100005
#define wr cout << "Continue debugging\n";
#define all(x) (x).begin(), (x).end()
#define ll long long int
#define pii pair <int, int>
#define pb push_back
#define ff first
#define ss second
using namespace std;

string s[N];

bool cmp(string a, string b) {
    return a+b < b+a;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
	}
	sort(s+1,s+n+1,cmp);
	for (int i = 1; i <= n; i++){
		cout << s[i];
	}
}	