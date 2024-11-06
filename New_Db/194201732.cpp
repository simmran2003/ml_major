#include <cmath>
#include <iostream>
using namespace std;
int n, m, block;
int op, x, y;
int a[2000005], pre[2000005], sum[2000005];
int sec (int x) {return (x - 1) / block + 1;}
void modify (int l) {
	sum[l] = 0;
	int s = sec (l), tmp = l;
	while (sec (tmp) == s && tmp <= n) {
		tmp += a[tmp];
		++ sum[l];
	}
	pre[l] = tmp;
}
int main () {
	scanf ("%d%d", &n, &m);
	block = sqrt (n);
	for (int i = 1; i <= n; i ++) scanf ("%d", &a[i]);
	for (int i = 1; i <= n; i ++) modify (i);
	for (int i = 1; i <= m; i ++) {
		scanf ("%d%d", &op, &x);
		if (op == 0) {
			scanf ("%d", &y);
			a[x] = y;
			for (int j = x; j>=(sec(x)-1)*block+1; -- j) {
				if (j + a[j] > min(sec(x)*block,n) ) {
					pre[j] = j + a[j];
					sum[j] = 1;
				}
				else {
					pre[j] = pre[j + a[j] ];
					sum[j] = sum[j + a[j] ] + 1;
				}
			}
		}
		else {
			int ans = 0;
			while (pre[x] <= n) {
				ans += sum[x];
				x = pre[x];
			}
			while (x + a[x] <= n) {
				++ ans;
				x += a[x];
			}
			printf ("%d %d\n", x, ans + 1);
		}
	}
	return 0;
}
