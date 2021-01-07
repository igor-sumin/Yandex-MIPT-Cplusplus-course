#include <bits/stdc++.h>

using namespace std;

// Мое решение
template <typename T>
vector<T> FindGreaterElements1(const set<T>& elements, const T& border) {
	auto bm = find_if(elements.begin(), elements.end(), [&](const T& s) {
		return border < s;
	});

	vector<T> res;
	for(auto it = bm; it != elements.end(); it++) {
		res.push_back(*it);
	}

	return res;
}

// Мое решение 2
template <typename T>
vector<T> FindGreaterElements2(const set<T>& elements, const T& border) {
	auto bm = find_if(elements.begin(), elements.end(), [&](const T& s) {
		return border < s;
	});

	return {bm, elements.end()};
}

// Альтернативное решение
template <typename T>
vector<T> FindGreaterElements3(const set<T>& elements, const T& border) {
	// Начнём итерироваться по множеству
	auto it = begin(elements);
	// Цель — найти первый элемент, больший border
	// Если итератор не достиг конца и указывает не туда, двигаем
	while (it != end(elements) && *it <= border) {
		++it;
	}
	// Возвращаем вектор, созданный из элементов множества, начиная с it
	return {it, end(elements)};
}

int main() {
	for (int x : FindGreaterElements3(set<int>{1, 5, 7, 8}, 5)) {
		cout << x << " ";
	} cout << endl;	// 7 8

	string to_find = "Python";
	cout << FindGreaterElements3(set<string>{"C", "C++"}, to_find).size() << endl;	// 0

	return 0;
}