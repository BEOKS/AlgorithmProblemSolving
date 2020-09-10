#include <iostream>
#include <algorithm>
const int MAX_LEN = 10000;
using namespace std;
string number;
int cache[MAX_LEN];
int hard(string number) {
	if (number == string(number.size(), number[0])) {
		return 1;
	}
	bool progrssive=true;
	for (int i = 1; i < number.size() - 1; i++) {
		if (number[i] - number[i + 1] != number[0] - number[1]) {
			progrssive = false;	
			break;
		}
	}
	if (progrssive) {
		if (abs(number[0] - number[1]) == 1) {
			return 2;
		}
		return 5;
	}
	bool alternating = true;
	for (int i = 0; i < number.size(); i++) {
		if (number[i] != number[i % 2]) {
			alternating = false;
			break;
		}
	}
	return alternating?4:10;
}
int solve(int start) {
	if (start >= number.size())	return 0;
	int& ret = cache[start];
	if (ret != -1) {
		return ret;
	}
	ret = numeric_limits<int>::max();
	for (int i = 3; i <= 5; i++) {
		ret = min(ret, hard(number.substr(start, i)) + solve(start + i));
	}
	return ret;
}
void PI() {
	int t;
	cin >> t;
	for (int c = 0; c < t; c++) {
		cin >> number;
		fill(&cache[0], &cache[MAX_LEN], -1);
		cout << solve(0) <<"\n";
	}
}