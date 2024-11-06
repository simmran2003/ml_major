#include <algorithm>
#include <iostream>

using namespace std;

long long cross(int x0, int y0, int x1, int y1) {
	return (long long) x0 * y1 - (long long) x1 * y0;
}

long long cross(int x0, int y0, int x1, int y1, int x2, int y2) {
	return cross(x1 - x0, y1 - y0, x2 - x0, y2 - y0);
}

long long dot(int x0, int y0, int x1, int y1) {
	return (long long) x0 * x1 + (long long) y0 * y1;
}

bool check2(int xl0, int yl0, int xr0, int yr0, int xl1, int yl1, int xr1, int yr1, int xl2, int yl2, int xr2, int yr2) {
	if (xl0 != xl1 || yl0 != yl1)
		return false;
	if (xr0 == xr1 && yr0 == yr1)
		return false;
	if (dot(xr0 - xl0, yr0 - yl0, xr1 - xl1, yr1 - yl1) < 0)
		return false;
	if (cross(xl0, yl0, xr0, yr0, xl2, yl2))
		return false;
	if (cross(xl1, yl1, xr1, yr1, xr2, yr2))
		return false;
	if (xl2 < xl0 && xl2 < xr0)
		return false;
	if (xl2 > xl0 && xl2 > xr0)
		return false;
	if (yl2 < yl0 && yl2 < yr0)
		return false;
	if (yl2 > yl0 && yl2 > yr0)
		return false;
	if (xr2 < xl1 && xr2 < xr1)
		return false;
	if (xr2 > xl1 && xr2 > xr1)
		return false;
	if (yr2 < yl1 && yr2 < yr1)
		return false;
	if (yr2 > yl1 && yr2 > yr1)
		return false;
	int l, r;
	if (xl0 != xr0) {
		l = xl0 - xl2;
		r = xl2 - xr0;
	} else {
		l = yl0 - yl2;
		r = yl2 - yr0;
	}
	l = abs(l);
	r = abs(r);
	if (l > r)
		swap(l, r);
	if (l * 4 < r)
		return false;
	if (xl1 != xr1) {
		l = xl1 - xr2;
		r = xr2 - xr1;
	} else {
		l = yl1 - yr2;
		r = yr2 - yr1;
	}
	l = abs(l);
	r = abs(r);
	if (l > r)
		swap(l, r);
	if (l * 4 < r) {
		return false;
	}
	return true;
}

bool check1(int xl0, int yl0, int xr0, int yr0, int xl1, int yl1, int xr1, int yr1, int xl2, int yl2, int xr2, int yr2) {
	if (check2(xl0, yl0, xr0, yr0, xl1, yl1, xr1, yr1, xl2, yl2, xr2, yr2))
		return true;
	if (check2(xr0, yr0, xl0, yl0, xl1, yl1, xr1, yr1, xl2, yl2, xr2, yr2))
		return true;
	if (check2(xl0, yl0, xr0, yr0, xr1, yr1, xl1, yl1, xl2, yl2, xr2, yr2))
		return true;
	if (check2(xl0, yl0, xr0, yr0, xl1, yl1, xr1, yr1, xr2, yr2, xl2, yl2))
		return true;
	if (check2(xl0, yl0, xr0, yr0, xr1, yr1, xl1, yl1, xr2, yr2, xl2, yl2))
		return true;
	if (check2(xr0, yr0, xl0, yl0, xl1, yl1, xr1, yr1, xr2, yr2, xl2, yl2))
		return true;
	if (check2(xr0, yr0, xl0, yl0, xr1, yr1, xl1, yl1, xl2, yl2, xr2, yr2))
		return true;
	if (check2(xr0, yr0, xl0, yl0, xr1, yr1, xl1, yl1, xr2, yr2, xl2, yl2))
		return true;
	return false;
}

bool check0(int xl0, int yl0, int xr0, int yr0, int xl1, int yl1, int xr1, int yr1, int xl2, int yl2, int xr2, int yr2) {
	if (check1(xl0, yl0, xr0, yr0, xl1, yl1, xr1, yr1, xl2, yl2, xr2, yr2))
		return true;
	if (check1(xl1, yl1, xr1, yr1, xl2, yl2, xr2, yr2, xl0, yl0, xr0, yr0))
		return true;
	if (check1(xl2, yl2, xr2, yr2, xl0, yl0, xr0, yr0, xl1, yl1, xr1, yr1))
		return true;
	return false;
}

int main() {
	int t; cin >> t;
	for (int h = 0; h < t; h++) {
		int xl0, yl0, xr0, yr0; cin >> xl0 >> yl0 >> xr0 >> yr0;
		int xl1, yl1, xr1, yr1; cin >> xl1 >> yl1 >> xr1 >> yr1;
		int xl2, yl2, xr2, yr2; cin >> xl2 >> yl2 >> xr2 >> yr2;
		cout << (check0(xl0, yl0, xr0, yr0, xl1, yl1, xr1, yr1, xl2, yl2, xr2, yr2) ? "YES" : "NO") << '\n';
	}
	return 0;
}
