#include <iostream>
using namespace std;
const int MAXN = 10;
int getNextStudent(int n,bool* isSelected) {
	for (int i = 0; i < n; i++) {
		if (isSelected[i] == false) {
			return i;
		}
	}
	return n;
}
int solve(int n, bool isFriend[MAXN][MAXN], bool* isSelected) {
	int next = getNextStudent(n, isSelected);
	if (next == n)	return 1;
	int sum = 0;
	for (int i = next+1; i < n; i++) {
		if (isFriend[next][i] && isSelected[i] == false) {
			isSelected[next] = isSelected[i] = true;
			sum += solve(n, isFriend, isSelected);
			isSelected[next] = isSelected[i] = false;
		}
	}
	return sum;
}
void picnic() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int n, m;
		cin >> n >> m;
		bool isFriend[MAXN][MAXN] = { false };
		bool isSelected[MAXN] = { false };
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			isFriend[a][b] = isFriend[b][a] = true;
		}
		cout << solve(n, isFriend, isSelected) << "\n";
	}
}