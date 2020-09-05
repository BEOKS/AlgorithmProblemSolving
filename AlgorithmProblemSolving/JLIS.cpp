#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int m, n;
int* seq1, *seq2;
int cache[101][101];
int solve(int i1, int i2) {
	int& ret = cache[i1][i2];
	if (ret != -1)	return ret;
	if (i1 == n && i2 == m) {
		return ret = 0;
	}
	//pick i1
	if (seq1[i1] < seq2[i2]) {
		for (int i = i1 + 1; i < n && seq1[i1] < seq1[i]; i++) {
			ret = max(ret, 1 + solve(i, i2));
		}
		for (int i = i2; i < m && seq1[i1] < seq2[i]; i++) {
			ret = max(ret, 1 + solve(i1+1, i));
		}
	}
	else {//pick i2
		for (int i = i1; i < n && seq2[i2] < seq1[i]; i++) {
			ret = max(ret, 1 + solve(i, i2+1));
		}
		for (int i = i2+1; i < m && seq2[i2] < seq2[i]; i++) {
			ret = max(ret, 1 + solve(i1, i));
		}
	}
	//no pick
	ret = max(ret, solve(i1 + 1, i2 + 1));
}
void jlis() {
	int c;
	cin >> c;
	for (int t = 0; t < c; t++) {
		cin >> n >> m;
		fill(&cache[0][0], &cache[100][101], -1);
		seq1 = new int[n];	seq2 = new int[m];
		for (int i = 0; i < n; i++) {
			cin >> seq1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> seq2[i];
		}
		cout << solve(0, 0) << "\n";
	}
}