#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// функция сортировки без учёта регистра
bool Case_insensitive(const string& s1, const string& s2) {
	string res1, res2;
	for (const char& s : s1) {
		res1.push_back(tolower(s));
	}

	for (const char& s : s2) {
		res2.push_back(tolower(s));
	}

	return res1 < res2;
}

int main() {
	int n = 0;
	cin >> n;

	vector<string> res(n);
	for (string& item : res) {
		cin >> item;
	};

	sort(res.begin(), res.end(), Case_insensitive);

	for (const string& item : res) {
		cout << item << " ";
	} cout << endl;

	return 0;
}