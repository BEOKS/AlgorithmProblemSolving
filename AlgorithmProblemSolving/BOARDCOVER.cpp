#include <iostream>
using namespace std;
int* getNext(int h, int w, char board[20][20]) {
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			if (board[row][col]=='.') {
				int ret[2] = { row,col };
				return ret;
			}
		}
	}
	return NULL;
}
int type[4][3][2] = {
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{0,1}}
};
bool possible(int h,int w,int type[3][2], char board[20][20], int *next) {
	for (int i = 0; i < 3; i++) {
		if (next[0] + type[i][0] == h || next[1] + type[i][1] == w) {
			return false;
		}
		if (board[next[0] + type[i][0]][next[1] + type[i][1]] == '#') {
			return false;
		}
	}
	return true;
}
void insert(int type[3][2], char board[20][20], int next[2]) {
	for (int i = 0; i < 3; i++) {
		board[next[0] + type[i][0]][next[1] + type[i][1]] = '#';
	}
}
void erase(int type[3][2], char board[20][20], int next[2]) {
	for (int i = 0; i < 3; i++) {
		board[next[0] + type[i][0]][next[1] + type[i][1]] = '.';
	}
}
int solve(int h, int w, char board[20][20]) {
	int* next = getNext(h, w, board);
	if (next == NULL) {
		return 1;
	}

	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (possible(h,w,type[i], board, next)) {
			insert(type[i], board, next);
			sum += solve(h, w, board);
			erase(type[i], board, next);
		}
	}
	return sum;

}
void boardCover() {
	int c=0;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int h, w;
		cin >> h >> w;
		char board[20][20];
		for (int row = 0; row < h; row++) {
			for (int col = 0; col < w; col++) {
				cin >> board[row][col];
			}
		}
		cout << solve(h, w, board) << "\n";
	}
}