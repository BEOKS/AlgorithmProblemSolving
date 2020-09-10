#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> board;
int solve1(int left,int right) {
	if (right < left)	return -1;
	if (left == right) {
		return board[left];
	}
	int minV = numeric_limits<int>::max(),mini=0;
	for (int i = left; i <= right; i++) {
		if (minV > board[i]) {
			mini = i;
			minV = board[i];
		}
	}
	int ret = minV * (right-left + 1);
	ret = max(ret, solve1(left, mini-1));
	ret = max(ret, solve1(mini+1, right));
	return ret;
}
void fence() {
	int c;
	cin >> c;
	for (int t = 0; t < c; t++) {
		int n;
		cin >> n;
		board.clear();
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			board.push_back(temp);
		}
	cout << solve1(0,board.size()-1) << "\n";
	}
}