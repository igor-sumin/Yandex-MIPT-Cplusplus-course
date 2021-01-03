#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n = 0;
	cin >> n;

	vector<int> res(n);
	for (int& r : res) {
		cin >> r;
	}

	// производим сортировку по модулю
	sort(res.begin(), res.end(), [](int x1, int x2) {
		return abs(x1) < abs(x2);
	});

	for (const int& r : res) {
		cout << r << " ";
	} cout << endl;

	return 0;
}