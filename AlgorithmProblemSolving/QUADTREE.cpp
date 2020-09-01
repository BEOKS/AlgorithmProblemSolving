#include <iostream>
#include <vector>
using namespace std;
int index = 0;
string reverse(string tree) {
	if (tree[index] != 'x') {
		return string(1,tree[index]);
	}
	index++;
	string a1 = reverse(tree);	
	index++;
	string a2 = reverse(tree);	
	index++;
	string a3 = reverse(tree);
	index++;
	string a4 = reverse(tree);
	return "x"+a3 + a4 + a1 + a2;
}
void quadTree() {
	int c;
	cin >> c;
	for (int t = 0; t < c; t++) {
		string tree;	
		index = 0;
		cin >> tree;
		cout << reverse(tree) << "\n";
	}
}