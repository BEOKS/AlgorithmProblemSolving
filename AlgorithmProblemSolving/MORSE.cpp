#include <iostream>
#include <algorithm>
using namespace std;
int m, n, k;
const int MAX = 1000000000;
int bino[201][201];

string solve(int n, int m, int k) {
	if (n == 0)	return string(m, 'o');
	if (k < bino[n + m - 1][n - 1]) {
		return "-" + solve(n-1, m, k);
	}
	return "o" + solve(n, m - 1, k - bino[n + m - 1][n - 1]);
}

int cal() {
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 0; j <= 200; j++) {
			bino[i][j] = min(MAX, bino[i - 1][j] + bino[i - 1][j - 1]);
		}
	}
}
void MORSE() {
	cin >> m >> n >> k;
	cout << solve(m, n, k);
}