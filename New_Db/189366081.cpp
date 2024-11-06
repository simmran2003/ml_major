// BEGIN BOILERPLATE CODE

#include <bits/stdc++.h>
using namespace std;

#ifdef KAMIRULEZ
	const bool kami_loc = true;
	const long long kami_seed = 69420;
#else
	const bool kami_loc = false;
	const long long kami_seed = chrono::steady_clock::now().time_since_epoch().count();
#endif

const string kami_fi = "kamirulez.inp";
const string kami_fo = "kamirulez.out";
mt19937_64 kami_gen(kami_seed);

long long rand_range(long long rmin, long long rmax) {
	uniform_int_distribution<long long> rdist(rmin, rmax);
	return rdist(kami_gen);
}

long double rand_real(long double rmin, long double rmax) {
	uniform_real_distribution<long double> rdist(rmin, rmax);
	return rdist(kami_gen);
}

void file_io(string fi, string fo) {
	if (fi != "" && (!kami_loc || fi == kami_fi)) {
		freopen(fi.c_str(), "r", stdin);
	}
	if (fo != "" && (!kami_loc || fo == kami_fo)) {
		freopen(fo.c_str(), "w", stdout);
	}
}

void set_up() {
	if (kami_loc) {
		file_io(kami_fi, kami_fo);
	}
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

void just_do_it();

void just_exec_it() {
	if (kami_loc) {
		auto pstart = chrono::steady_clock::now();
		just_do_it();
		auto pend = chrono::steady_clock::now();
		long long ptime = chrono::duration_cast<chrono::milliseconds>(pend - pstart).count();
		string bar(50, '=');
		cout << '\n' << bar << '\n';
		cout << "Time: " << ptime << " ms" << '\n';
	}
	else {
		just_do_it();
	}
}

int main() {
	set_up();
	just_exec_it();
	return 0;
}

// END BOILERPLATE CODE

// BEGIN MAIN CODE

struct point {
	long long x = 0;
	long long y = 0;

	point() {

	}

	point(long long _x, long long _y) {
		x = _x;
		y = _y;
	}

	point operator-(point p2) {
		return point(x - p2.x, y - p2.y);
	}

	long long operator^(point p2) {
		return x * p2.y - y * p2.x; 
	}
};

ostream& operator<<(ostream &out, point p) {
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}

bool cmpx(point p1, point p2) {
	return p1.x < p2.x;
}

const int ms = 5e2 + 20;
point a[ms];
point b[ms];
int low1[ms];
int low2[ms][ms];

void just_do_it() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i].x >> b[i].y;
	}
	sort(a + 1, a + n + 1, cmpx);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			low1[i] += (a[i].x == b[j].x) && (b[j].y < a[i].y);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int s = 0;
			for (int k = 1; k <= m; k++) {
				if (b[k].x < a[i].x || b[k].x > a[j].x) {
					continue;
				}
				s += ((b[k] - a[i]) ^ (a[j] - a[i])) > 0;
			}
			low2[i][j] = low2[j][i] = s;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (low2[i][j] + low2[j][k] - low1[j] == low2[i][k]) {
					res++;
				}
			}
		}
	}
	cout << res;
}

// END MAIN CODE