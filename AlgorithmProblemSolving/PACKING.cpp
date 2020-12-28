#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cache[1001][101];
int N, W,w[101],J[101];
char name[1001][21];
int pack(int capacity, int item_index) {
	int& ret = cache[capacity][item_index];
	if (ret != -1)	return ret;
	if (item_index == N)	return ret = 0;
	ret = pack(capacity, item_index + 1);
	if (capacity + w[item_index] <= W) {
		ret = max(ret, pack(capacity + w[item_index], item_index + 1) + J[item_index]);
	}
	return ret;
}
void printResult() {
	int max_weight = pack(0, 0);
	vector<int> list;
	for (int i = 0,capacity=0; i < N; i++) {
		if (pack(capacity, i) != pack(capacity, i + 1)) {
			list.push_back(i);
			capacity += w[i];
		}
	}
	cout << max_weight << " " << list.size() << "\n";
	for (int i : list) {
		cout << name[i] << "\n";
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