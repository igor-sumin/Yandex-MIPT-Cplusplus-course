#include <bits/stdc++.h>

using namespace std;

// Решение в лоб
template <typename T>
void RemoveDuplicates1(vector<T>& elements) {
	set<T> res;
	for(auto s : elements) {
		res.insert(s);
	}

	elements.clear();
	for(auto s : res) {
		elements.push_back(s);
	}
}

// Корректное решение
template <typename DataType>
void RemoveDuplicates(vector<DataType>& elements) {
	sort(elements.begin(), elements.end());
	elements.erase(unique(elements.begin(), elements.end()), elements.end());
}

int main() {
	vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
	RemoveDuplicates2(v1);
	for (int x : v1) {
		cout << x << " ";	// 6 4 7 0 1
	} cout << endl;

	vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
	RemoveDuplicates2(v2);
	for (const string& s : v2) {
		cout << s << " ";	// C++ C
	} cout << endl;

	return 0;
}