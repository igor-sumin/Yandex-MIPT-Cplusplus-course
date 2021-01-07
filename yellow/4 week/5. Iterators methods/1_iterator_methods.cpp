#include <bits/stdc++.h>

using namespace std;

template <typename It>
void PrintRange(It range_begin, It range_end) {
	for(auto it = range_begin; it != range_end; ++it) {
		cout << *it << " ";
	} cout << endl;
}

int main() {
	vector<string> langs = {
		"Python", "C++", "C", "Java", "C#"	
	};

	//-> Удаление элемента по итератору

	auto it = find(langs.begin(), langs.end(), "C++");
	langs.erase(it);
	PrintRange(langs.begin(), langs.end());
	// Удаление: [it, end)
	langs.erase(it, langs.end());

	//-> Вставка элементов
	
	// v.insert(it, value) вставляет value перед итератором it
	// Вставление элемента в начало
	langs.insert(langs.begin(), "C++");

	// v.insert(it, range_begin, range_end) вставляет диапазон [range_begin, range_end) в позицию it
	// v.insert(it, count, value) count раз вставляет элемент value в позицию it
	langs.insert(it, {1, 2, 3}) 	// вставляет 1, 2, 3 в позицию it

	// ...

	// (!) Алгоритмы, принимающие итераторы, не влияют на размер контейнера

	// Метод сдвинул элементы, не начинающиеся на С влево и выдал итератор, на последний элемент, в котором в начале нет С
	auto it = remove_if(langs.begin(), langs.end(), [](const string& lang) {
		return langs[0] == 'C';
	});
	PrintRange(langs.begin(), langs.end());

	// Удалили элементы, начинающиеся на C
	langs.erase(it, langs.end());

	// unigue удаляет подряд идущие повторные элементы
	auto it = unique(langs.begin(), langs.end());
	langs.erase(it, langs.end());
	PrintRange(langs.begin(), langs.end());

	// Находит минимальный элемент в контейнере
	auto it = min_element(langs.begin(), langs.end());
	cout << *it << endl;

	// Аналог max_element
	auto it = max_element(langs.begin(), langs.end());
	cout << *it << endl;

	// Сразу оба метода
	auto p = minmax_element(langs.begin(), langs.end());
	cout << p->first << ", " << p->second << endl;


	// Проверяет какое-то свойство для всех элементов диапазона
	all_of(langs.begin(), langs.end(), [](const string& s){
		return s[0] >= 'A' && s[0] <= 'Z';
	});	// выведет 1 (true), так как все названия языков удовлетворяют условию лямбда-функции

	return 0;
}