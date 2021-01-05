#include <bits/stdc++.h>
using namespace std;

// Пишем универсальную шаблонную функцию
template <typename Collection>
string Join(const Collection& c, char d) {
	stringstream ss;
	bool first = true;
	for(const auto& i : c) {
		if(!first) {
			ss << d;
		} first = false;

		ss << i;		
	}

	return ss.str();
}

// для контейнеров, имеющих два шаблонных аргумента - pair
template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p) {
	return out << '(' << p.first << ", " << p.second << ')';
}

// для контейнеров, имеющих один шаблонный аргумент - vector
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vi) {
	// так как возвращает ссылку на поток, то решение можно написать в строчку
	return out << '[' << Join(vi, ',') << ']';
}

// для контейнеров, имеющих два шаблонных аргумента - map
template <typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& mp) {
	return out << '{' << Join(mp, ',') << '}';
}

int main() {
	vector<int> vi = {1, 2, 3};
	vector<double> vd = {1.2, 2.4, 3.5};
	cout << vi << ", " << vd << endl;
	// [1,2,3], [1.2,2.4,3.5]

	map<int, int> mi = {{1, 2}, {3, 4}};
	map<int, double> md = {{1, 2.1}, {3, 4.1}};
	cout << mi << ", " << md << endl;
	// {(1, 2),(3, 4)}, {(1, 2.1),(3, 4.1)}

	vector<vector<int>> vvi = {{1, 3}, {5, 6}, {1, 4}};
	cout << vvi << endl;
	// [[1,3],[5,6],[1,4]] - это круто

	return 0;
}