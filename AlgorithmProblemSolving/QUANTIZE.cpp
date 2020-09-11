#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> numbers;
int n, s;
int cache[101][11];
int pSum[100],pSqr[100];
int minError(int start, int end) {
	int sum = pSum[end] - start == 0 ? 0 : pSum[start];
	int sqr = pSqr[end] - start == 0 ? 0 : pSqr[start];
	int a = round(sum / ((double)end - start+1));
	return (end - start + 1) * a - 2 * a * sum + sqr;

}
int solve(int start, int restNum) {
	if (start == n)	return 0;
	if (restNum == 0)	return numeric_limits<int>::max();
	int& ret = cache[start][restNum];
	if (ret != -1)	return ret;
	ret = numeric_limits<int>::max();
	for (int i = start+1; i + restNum <= n; i++) {	
		ret = min(ret, solve(start, restNum - 1) + minError(start, i));
	}
}
void QUANTIZE() {
	int t;
	cin >> t;
	for (int c = 0; c < t; c++) {
		numbers.clear();
		fill(&cache[0][0], &cache[100][11], -1);
		cin >> n >> s;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			numbers.push_back(temp);
			sort(numbers.begin(), numbers.end());
			int sum = 0,sqr=0;
			for (int j = 0; j < n; j++) {
				sum += numbers[j];	sqr += numbers[j] * numbers[j];
				pSum[j] = sum;	pSqr[j] = sqr;
			}
			cout << solve(0, s);
		}
	}
}