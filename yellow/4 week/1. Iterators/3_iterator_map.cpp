#include <bits/stdc++.h>

using namespace std;

template <typename It>
void PrintRange(It range_begin, It range_end) {
	for(auto it = range_begin; it != range_end; ++it) {
		cout << *it << " ";
	} cout << endl;
}

template <typename It>
void PrintMapRange(It range_begin, It range_end) {
	for(auto it = range_begin; it != range_end; ++it) {
		cout << it->first << ", " << it->second << endl;
	} cout << endl;
}

int main() {
	set<string> langs = {
		"Python", "C++", "C", "Java", "C#"
	};

	PrintRange(langs.begin(), langs.end());

	auto border = langs.find("C++");
	// Получим все строчки, которые меньше C++, так как словарь упорядочил элементы
	PrintRange(langs.begin(), border);
	// Получим все элементы множества, который больше либо равны "C++".
	PrintRange(border, langs.end());

	// ...

	map<string, int> langs2 = {
		{"Python", 26}, {"C++", 34}, {"C", 45}, {"Java", 22}, {"C#", 17}
	};

	auto it2 = langs2.find("C++");
	PrintMapRange(langs2.begin(), it2);
	PrintMapRange(it2, langs2.end());

	return 0;
}