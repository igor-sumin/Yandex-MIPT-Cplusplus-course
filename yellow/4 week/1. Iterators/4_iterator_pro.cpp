#include <bits/stdc++.h>

using namespace std;

int main() {
	// Итераторы есть у всех контейнеров
	// Итераторы предоставляют универсальный способ обхода контейнеров
	// range-based for всё равно удобнее

	vector<string> langs = {
		"Python", "C++", "C", "Java", "C#"	
	};

	// Итерирование в обратную сторону
	auto it = langs.end();
	while(it != langs.begin()) {
		--it;
		cout << *it << " ";
	} cout << endl;

	return 0;
}