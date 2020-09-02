#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string wildPat, str;
int cache[101][101];
bool check(int wildPatIndex, int strIndex) {
	int& ret = cache[wildPatIndex][strIndex];
	if (ret != -1) {
		return ret;
	}
	if (wildPatIndex == wildPat.size())	return ret = (strIndex == str.size()?1:0);
	if (wildPatIndex < wildPat.size() && strIndex < str.size() &&
		(wildPat[wildPatIndex] == '?' || str[strIndex] == wildPat[wildPatIndex])) {
		return ret = check(wildPatIndex+1, strIndex+1);
	}
	if (str[strIndex] == '*') {
		if (check(wildPatIndex + 1, strIndex) ||
			(strIndex < str.size() && check(wildPatIndex, strIndex + 1))) {
			return ret=1;
		}
	}
	return ret = 0;
}
void wildCard() {
	int c;
	cin >> c;
	for (int t = 0; t < c; t++) {
		fill(&cache[0][0], &cache[100][100]+1, -1);
		cin >> wildPat;
		int n;
		cin >> n;
		vector<string> result;
		for (int i = 0; i < n; i++) {
			cin >> str;
			if (check(0, 0)==1) {
				result.push_back(str);
			}
		}
		sort(result.begin(), result.end());
		for (string str : result) {
			cout << str << "\n";
		}
	}
}