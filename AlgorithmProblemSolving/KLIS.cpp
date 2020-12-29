#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k,S[500],countLIS[500],LISlen[500];
void printKthLIS(int index, int skip) {
	if (index == n)	return;
	vector<pair<int, int>> list;
	for (int k = index + 1; k < n; k++) {
		if (index == -1 || LISlen[index] == LISlen[k] + 1 && S[index] < S[k]) {
			list.push_back(make_pair(S[k], k));
		}
	}
	sort(list.begin(), list.end());
	for (pair<int, int> temp : list) {
		if (countLIS[temp.second] <= skip) {
			skip -= countLIS[temp.second];
		}
		else {
			cout << temp.first;
			printKthLIS(index, skip);
			break;
		}
	}
}
int lis1(int index) {
	if (index == n-1)	return LISlen[index]=1;
	int& ret = LISlen[index];
	if (ret != 0)	return ret;
	for (int k = index + 1; k < n; k++) {
		ret = max(ret, index==-1||S[index] < S[k] ? lis1(k) + 1 : 0);
	}
	return ret;

}
int lis2(int index) {
	if (LISlen[index]==1)	return countLIS[index] = 1;
	int& ret = countLIS[index];
	if (ret != 0)	return ret;
	for (int k = index + 1; k < n; k++) {
		ret = index == -1 || (S[index] < S[k] && LISlen[index] == LISlen[k] + 1) ? ret += lis2(k) : 0;
	}
	return ret;
	
}
void KLIS() {
	cin >> n >> k;
	int t = n;
	while (t--)
	{
		cin >> S[n - t];
	}
	lis1(-1);
	lis2(-1);
	printKthLIS(-1, k);
}