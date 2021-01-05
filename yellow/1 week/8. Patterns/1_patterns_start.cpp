#include <bits/stdc++.h>

using namespace std;

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2) {
	First f = p1.first * p2.first;
	Second s = p1.second * p2.second;

	return make_pair(f, s);
}

template <typename T>
T sqr(T x) {
	// работает для таких T, в которых определен operator*
	return x * x;
}

// ---

// для контейнеров, имеющих два шаблонных аргумента - pair
template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& vi) {
	out << p.first << ", " << p.second;

	return out;
}

// для контейнеров, имеющих один шаблонный аргумент - vector
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vi) {
	for(const auto& i : vi) {
		out << i << " ";
	}

	return out;
}

// для контейнеров, имеющих два шаблонных аргумента - map
template <typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& vi) {
	// нужно написать оператор вывода в поток для пары(pair) - тогда цикл заработает
	for(const auto& i : vi) {
		out << i << " ";
	}

	return out;
}

int main() {
	cout << sqr(3) << endl;   // 9
	cout << sqr(2.5) << endl; // 6.25

	auto p = make_pair(2.5, 3);
	// Напишем шаблонный operator* для пар
	auto res = sqr(p);
	cout << res.first << ", " << res.second << endl; // 6.25, 9

	// ---

	vector<int> vi = {1, 2, 3};
	vector<double> vd = {1.2, 2.4, 3.5};
	// Перегрузили шаблонный оператор вывода в поток для vector
	cout << vi << ", " << vd << endl;

	map<int, int> mi = {{1, 2}, {3, 4}};
	map<int, double> md = {{1, 2.1}, {3, 4.1}};
	// Перегрузили шаблонный оператор вывода в поток для map, при этом
	// во избежание ошибок компиляции, нам потребовалось перегрузить оператор вывода и для pair
	cout << mi << ", " << md << endl;

	return 0;
}