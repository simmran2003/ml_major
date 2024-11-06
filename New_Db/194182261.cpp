// LUOGU_RID: 102496037
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 50005;
string s[maxn];
int n;
bool cmp(string a, string b) {
	return a + b < b + a;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	sort(s + 1, s + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		cout << s[i];
	}
	return 0;
}