#include <iostream>
#include <algorithm>
using namespace std;
int N, W;
string name[100];
int w[100], J[100];
int cache[1001][101];
int solve(int W, int index) {
	int& ret = cache[W][index];
	if (ret != -1) {
		return ret;
	}
	if (index == N || W==0) {
		return ret = 0;
	}
	if (w[index] <= W) {
		ret = max(ret, solve(W - w[index], index + 1) + J[index]);
	}
	return ret = max(ret, solve(W, index + 1));
}
void printResult() {
	cout << solve(W, 0);
	int capacity = W,count=0;
	for (int i = 0; i < N; i++) {
		if (cache[capacity][i] != cache[capacity][i + 1]) {
			capacity -= w[i];
			count++;
		}
	}
	cout << " " << count << "\n";
	capacity = W;
	for (int i = 0; i < N; i++) {
		if (cache[capacity][i] != cache[capacity][i + 1]) {
			capacity -= w[i];
			cout << name[i] << "\n";
		}
	}
}
void PACKING() {
	fill(&cache[0][0], &cache[1000][101], -1);
	cin >> N >> W;
	for (int i = 0; i < N; i++) {
		cin >> name[i] >> w[i] >> J[i];
	}
	printResult();
}