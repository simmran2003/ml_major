#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
typedef long long ll;
typedef struct p {
	ll x, y;
}p;
p r[505], b[505];
ll f[505][505];
bool cmp(p a, p b)
{
	return a.y < b.y;
}
bool toleft(p i, p j, p k)//判断点k是否在i->j的左侧
{
	if (k.y >= max(i.y, j.y) || k.y < min(i.y, j.y))return 0;
	return (i.x * j.y + k.x * i.y + j.x * k.y - k.x * j.y - i.x * k.y - j.x * i.y) > 0;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> r[i].x >> r[i].y;
	for (int i = 1; i <= m; i++)
		cin >> b[i].x >> b[i].y;
	sort(r + 1, r + n + 1, cmp);
	sort(b + 1, b + m + 1, cmp);
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			for (int k = 1; k <= m; k++)
				if (toleft(r[i], r[j], b[k]))f[i][j]++;
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << f[i][j] << " ";
		cout << endl;
	}*/
	ll ans = 0;
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k <= n; k++)
				if (f[i][j] + f[j][k] == f[i][k]) ans++;
	cout << ans << endl;
	return 0;
}