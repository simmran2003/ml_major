#include<bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, p;
	std::cin >> n >> p;

	std::vector<std::string> s(n);

	for (auto &i : s) {
		std::cin >> i;
	}

	i64 tmp = 0, ans = 0;
	while (n--) {
		tmp += s[n].size() > 4;
		ans += tmp * p;
		tmp <<= 1;
	}

	std::cout << ans / 2;
	return 0;
}