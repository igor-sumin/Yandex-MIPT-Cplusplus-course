#include <bits/stdc++.h>

using namespace std;

int main() {
	// Алгоритмы поиска
	// count и find

	// Подсчет количества
	count(v.begin(), v.end(), x);
	s.count(x);

	// Поиск
	find(v.begin(), v.end(), x);
	s.find(x);

	// ...

	// Поиск в неотсортированном векторе
	find(v.begin(), v.end(), x);
	find_if(v.begin(), v.end(), [](int y) {...});
	count(v.begin(), v.end(), x);

	// Перебор всех пробелов строки
	for(auto it = find(s.begin(), s.end(), ' '); it != s.end(); it = find(next(it), s.end(), ' ')) {
		cout << it - s.begin() << " ";
	}

	// Поиск в отсортированном векторе
	// Проверка на существование:
	binary_search(v.begin(), v.end(), x);
	// Первый элемент, больший или равный данному:
	lower_bound(v.begin(), v.end(), x);
	// Первый элемент, больший данного:
	upper_bound(v.begin(), v.end(), x);
	// Диапазон элементов, равных данному:
	equal_range(v.begin(), v.end(), x); /* == make_pair(lower_bound(...), upper_bound(...)); */
	// Если элемент есть,
	equal_range(v.begin(), v.end(), x); /* == [lower_bound, upper_bound) - диапазон всех значений */
	// Если элемента нет,
	// lower_bound == upper_bound - позиция, куда можно вставить элемент без нарушения порядка сортировки
	
	// Как найти количество вхождений:
	auto r = equal_range(v.begin(), v.end(), x);
	cout << r.second - r.first << endl;

	// Как перебрать все вхождения:
	auto r = equal_range(begin(v), end(v), x);
	for (auto it = r.first; it < r.second; ++it) {
		cout << *it << endl;
	}


	// (!) Раз мы каждый раз уменьшаем размер вдвое, то мы проделываем ровно столько операций, какова степень двойки нашего массива, 
	// то есть в какую степень надо возвести двойку, чтобы получить размер нашего диапазона. Это называется двоичным логарифмом в математике. 

	return 0;
}