#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	// Сумма температур может достигать 10^14, поэтому должна храниться в типе int64_t.
	int64_t sum = 0;

	vector<int> temp(n);
	for(auto& s : temp) {
		cin >> s;
		sum += s;
	}

	// Сумма температур может быть отрицательной, 
	// поэтому не должна делиться на беззнаковое число при вычислении среднего арифметического.
	int avg = sum / n;
	// int64_t avg = sum / static_cast<int64_t>(temp.size());

	int k = count_if(temp.begin(), temp.end(), [&](int x){
		return x > avg;
	});

	cout << k << endl;
	for(size_t i = 0; i < temp.size(); i++) {
		if(temp[i] > avg) {
			cout << i << " ";
		}
	}

	// 2 способ
	int n;
	cin >> n;
	vector<int> temperatures(n);
	int64_t sum = 0;
	for (int& temperature : temperatures) {
		cin >> temperature;
		sum += temperature;
	}

	int average = sum / n;

	vector<int> above_average_indices;
	for (int i = 0; i < n; ++i) {
		if (temperatures[i] > average) {
			above_average_indices.push_back(i);
		}
	}

	cout << above_average_indices.size() << endl;
	for (int i : above_average_indices) {
		cout << i << " ";
	}
	cout << endl;


	return 0;
}