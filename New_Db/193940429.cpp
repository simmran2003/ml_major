// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
	return a+b < b+a;
}

int main() {
	int n; cin >> n;
	vector<string> s;
	for(int i=0;i<n;i++){
		string a; cin >> a;
		s.push_back(a);
	}
	sort(s.begin(),s.end(),cmp);
	for(auto e:s){
		cout << e;
	}



	


}
