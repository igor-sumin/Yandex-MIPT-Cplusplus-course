#include <bits/stdc++.h>
#include <iterator>

using namespace std;

template <typename It>
void PrintRange(It range_begin, It range_end) {
	for(auto it = range_begin; it != range_end; ++it) {
		cout << *it << " ";
	} cout << endl;
}

int main() {
	// Обратные итераторы упрощают итерирование по контейнеру в обратную сторону

	vector<string> langs = {
		"Python", "C++", "C", "Java", "C#"
	};

	// Выведем вектор в обратном порядке
	// rbegin == reverse begin
	PrintRange(langs.rbegin(), langs.rend());

	// Вывод последнего элемента
	// rbegin указывает на последний элемент контейнера -> лучше, чем брать end() и делать --it
	cout << *langs.rbegin() << endl;

	auto it = langs.rbegin();
	cout << *it << " ";
	// Итератор подвинется в обратную сторону
	++it;
	cout << *it << " ";

	// ...

	auto it = find_if(langs.rbegin(), langs.rend(), [](const string& lang){
		return lang[0] == 'C';
	});

	cout << *it << endl;

	// ...

	// Переместим элементы, удовлетворяющие лямбда-функции, в начало диапазона, 
	// и возвращает итератор-разделитель border, указывающий на первый элемент, не удовлетворяющий критерию.
	auto it = partition(langs.begin(), langs.end(), [](const string& lang) {
		return lang[0] == 'C';
	});

	// Распечатываем то, что удовлетворяет partition
	PrintRange(langs.begin(), it);


	// Копируем элементы из langs в c_langs
	vector<string> c_lang(langs.size());
	// copy_if возвращает итератор it на новый конец вектора
	auto it = copy_if(langs.begin(), langs.end(), c_langs.begin(), [](const string& lang) {
		return lang[0] == 'C';
	});
	PrintRange(c_langs.begin(), it)

	// Удаляем пустые строки: "C++", "C", "C#", "", ""
	c_langs.erase(it, c_langs.end());
	PrintRange(c_langs.begin(), c_langs.end())

	// ...

	set<int> a = {1, 8, 3};
	set<int> b = {3, 6, 8};
	vector<int> v(a.size());
	// Пересечение двух множеств (также есть аналоги для работы с множествами)
	auto it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), v.begin());
	v.erase(it, v.end());
	PrintRange(v.begin(), v.end());

	// ...

	// back_inserter - вставляет элементы в конец контейнера (подобно push_back)
	// Копируемые элементы будут добавлены в конец независимо от того, пуст ли был c_langs изначально.
	vector<string> c_lang;
	copy_if(langs.begin(), langs.end(), back_inserter(c_langs), [](const string& lang) {
		return lang[0] == 'C';
	});
	PrintRange(c_langs.begin(), c_langs.end());

	// ...

	set<int> a = {1, 8, 3};
	set<int> b = {3, 6, 8};
	set<int> res;
	// Пересечение двух множеств II
	// inserter возвращает специальный итератор, который делает insert во множество set 
	auto it = set_intersection(
		a.begin(), a.end(), 
		b.begin(), b.end(),
		// в контейнер res суем элементы в конец
		inserter(res, res.end())
	);
	PrintRange(res.begin(), res.end());

	// ...

	// Разница между vector и set:
	// Производить операции (-+>< и тд) итераторов вектора можно, так как они храняться в обной области памяти, 
	// в отличие от множеств, у которых operator-, operator+ для итератораов неопределен из-за сложной структуры данных

	set<int> a = {1, 8, 3};
	auto it2 = s.find(6);
	// next(it2) == it2 + 1
	// prev(it2) == it2 - 1
	PrintRange(next(it2), s.end());

	return 0;
}