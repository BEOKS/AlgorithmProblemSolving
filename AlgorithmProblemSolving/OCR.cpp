#include <iostream>
using namespace std;
int m, q,B[500][11],T[500][500],M[500][500],n,R[100][11];
double cache[102][502];
int choice[102][502];

double recognize(int s, int p) {
	if (s == n)	return 0;
	double& ret = cache[s][p];
	if (ret != 1.0)	return ret;
	ret = -1e200;
	int& choose = choice[s][p];
	for (int next = 0; next < m; next++) {
		double cal = T[p][next] + M[next][R[s]] + recognize(s + 1, next);
		if (ret < cal) {
			ret = cal;
			choose = cal;
		}
	}
	return ret;
}
void print_result() {
	recognize(0, NULL);
}
void OCR() {
	//input
	scanf_s("%d %d", &m, &q);
	for (int i = 0; i < m; i++) {
		scanf_s("%s", B[i]);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &T[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &M[i][j]);
		}
	}
	for (int i = 0; i < q; i++) {
		scanf_s("%s", &n);
		for (int i = 0; i < n; i++) {
			scanf_s("%s", R[i]);
		}
		print_result();
	}
}