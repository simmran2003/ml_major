#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		mp[x]++;
	}

	vector<string> st;
	if (mp[5] != 0 || mp[7] != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	while (mp[1] > 0 && mp[2] > 0 && mp[4] > 0)
	{
		mp[1]--;
		mp[2]--;
		mp[4]--;
		st.push_back("1 2 4");
	}
	while (mp[1] > 0 && mp[3] > 0 && mp[6] > 0)
	{
		mp[1]--;
		mp[3]--;
		mp[6]--;
		st.push_back("1 3 6");
	}
	while (mp[1] > 0 && mp[2] > 0 && mp[6] > 0)
	{
		mp[1]--;
		mp[2]--;
		mp[6]--;
		st.push_back("1 2 6");
	}
	for (auto it : mp)
	{
		if (it.second > 0)
		{
			cout << -1 << endl;
			return 0;
		}
		
	}
	for (int i = 0; i < st.size(); i++)
			{
				cout << st[i] << endl;
			}
}