#include <iostream>
using namespace std;
int cache[101][101];
const int MOD = 10000000;
int solve(int n, int a) {
	int& ret = cache[n][a];
	if (n == a) {
		return ret=1;
	}
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int i = 1; i <= n - 1; i++) {
		ret += (a - 1 + i) * solve(n - a, i)%MOD;
		ret %= MOD;
	}
	return ret;
}
void POLY() {
	int t;
	cin >> t;
	for (int c = 0; c < t; c++) {
		int n;
		cin >> n;
		fill(&cache[0][0], &cache[100][101], -1);
		cout << solve(n+1,1);
	}
}