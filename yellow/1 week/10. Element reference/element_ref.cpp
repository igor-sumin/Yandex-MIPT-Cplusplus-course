#include <bits/stdc++.h>
using namespace std;

template <typename K, typename V> V& GetRefStrict(map<K, V>& mp, K value);

template <typename K, typename V>
V& GetRefStrict(map<K, V>& mp, K value) {
	// 1 способ
	auto it = mp.find(value);
	if (it == mp.end()) {
		throw runtime_error("no such key in dictionary");
	}
	
	return it->second;

	// 2 способ
	// if(mp.count(value) == 0) {
	// 	throw runtime_error("no such key in dictionary");
	// }

	// return mp[value];
}


int main() {
	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);

	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue

	return 0;
}