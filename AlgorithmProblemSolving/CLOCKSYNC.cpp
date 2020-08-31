#include <iostream>
#include <algorithm>
using namespace std;
char click[10][17] = {
	"oooxxxxxxxxxxxxx",
	"xxoxxxxoxoxoxxxx",
	"xxxxoxxxxxoxxxoo",
	"oxxxooooxxxxxxxx",
	"xxxxxxoooxoxoxxx",
	"oxoxxxxxxxxxxxoo",
	"xxxoxxxxxxxxxxoo",
	"xxxxooxoxxxxxxoo",
	"xoooooxxxxxxxxxx",
	"xxxoooxxxoxxxoxx"
};
int minV= numeric_limits<int>::max();
void push(char click[17], int clock[16]) {
	for (int i = 0; i < 16; i++) {
		if (click[i] == 'o') {
			if (clock[i] == 12) {
				clock[i] = 3;
			}
			else {
				clock[i] += 3;
			}
		}
	}
}
void solve(int clock[16],int clickNum,int level) {
	if (level == 10) {
		for (int i = 0; i < 16; i++) {
			if (clock[i] != 12) {
				return;
			}
		}
		minV = min(minV, clickNum);
		return;
	}
	if (clickNum > minV) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		solve(clock, clickNum + i, level + 1);
		push(click[level], clock);
	}
}
void clockSync() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int clock[16];
		for (int j = 0; j < 16; j++) {
			cin >> clock[j];
		}
		minV = numeric_limits<int>::max();
		solve(clock, 0, 0);
		if (minV == numeric_limits<int>::max())	minV = -1;
		cout << minV << '\n';
	}
}