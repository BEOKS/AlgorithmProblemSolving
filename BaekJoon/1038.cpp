#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>

using namespace std;

int N;
vector <long long> vec;

void Solve(long long index, int cnt) {
	if (cnt > 10) return;

	vec.push_back(index);
	for (int i = 0; i < 10; i++)
		if (index % 10 > i)
			Solve(index * 10 + i, cnt + 1);
	return;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N;

	for (int i = 0; i < 10; i++) 
		Solve(i, 1);
	
	sort(vec.begin(), vec.end());
    
	long long result = (vec.size() <= N) ? -1 : vec[N];
	cout << result;

	return 0;
}