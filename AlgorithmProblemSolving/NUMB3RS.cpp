#include <iostream>
using namespace std;
int n, d, p;
int A[50][50];
int edgeSum[50];
double cache[50][100];
double solve(int q, int d) {
	if (d == 0) {
		return q == p ? 1 : 0;
	}
	double& ret = cache[q][d];
	if (ret != 0) {
		return ret;
	}
	for (int i = 0; i < n; i++) {
		if (A[q][i] == 1) {
			ret += solve(i, d - 1) / edgeSum[i];
		}
	}
	return ret;
}
void NUMB3RS() {
	fill(&cache[0][0], &cache[49][100], 0);
	cin >> n >> d >> p;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			sum += A[i][j];
		}
		edgeSum[i] = sum;
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int q;
		cin >> q;
		cout << solve(q, d) << " ";
	}

}