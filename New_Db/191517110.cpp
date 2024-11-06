#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e15;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int boyut; cin >> boyut;
	vector<int> dizi(boyut + 1); set <int> dizi2;
	for(int i = 1; i <= boyut; i++)
	{
		cin >> dizi[i];
		dizi2.insert(dizi[i]);
	}

	vector <int> dizi3; dizi3.push_back(0);

	for(auto it = dizi2.begin(); it != dizi2.end(); it++)
		dizi3.push_back(*it);

	vector <int> dp(dizi2.size() + 1); 
	dp[0] = INF;
	for(int i = 1; i <= boyut; i++)
	{
		vector <int> dp2(dizi2.size() + 1);
		dp2[0] = INF;
		for(int j = 1; j <= dizi2.size(); j++)
		{
			dp2[j] = min(dp2[j -1], dp[j] + abs(dizi[i] - dizi3[j]));
		}

		/*
		for(int i = 1; i <= dizi2.size(); i++)
			cout << dp2[i] << " ";

		*/

		swap(dp, dp2);

		//cout << "\n";
	}

	cout << dp[dizi2.size()];

	return 0;
}