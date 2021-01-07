#include <bits/stdc++.h>

using namespace std;

using LangIt = vector<string>::iterator

// Подтип с названием итератор у контейнера вектора от string
template <typename It>
void PrintRange(It range_begin, It range_end) {
	for(auto it = range_begin; it != range_end; ++it) {
		cout << *it << " ";
	} cout << endl;
}

int main() {
	// Итератор - способ задать позицию в контейнере
	vector<string> langs = {
		"Python", "C++", "C", "Java", "C#"
	};

	auto result = find_if(langs.begin(), langs.end(), [](const string& lang) {
		return lang[0] == 'C';
	});

	// Ссылка на элемент, начинающийся на 'C'
	// Обращение к элементу
	cout << *result << endl;

	// Можем перезаписать элемент
	// 1 способ
	string& ref = *result;
	ref = "D++";

	// 2 способ
	*result = "D++";

	// ref и result теперь равны D++
	cout << ref << ", " << *result << endl;

	// ...

	string lang = langs[1];
	auto it = lang.begin();
	cout << *it << ", ";
	// Можем подвинуть итератор на следующий элемент контейнера
	++it;
	cout << *it << endl;	// C+

	// Идем в цикле по полуинтервалу: [begin, end)
	for(auto it = langs.begin(); it != langs.end(); ++it) {
		cout << *it << " ";
	} cout << endl;

	PrintRange(langs.begin(), langs.end());
	PrintRange(langs[0].begin(), langs[0].end());


	return 0;
}