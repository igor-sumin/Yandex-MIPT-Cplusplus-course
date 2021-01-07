#include <bits/stdc++.h>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	// 1. Если диапазон содержит меньше 2 элементов, выходим из функции
	if(range_end - range_begin < 2)	{
		return;
	}

	// Необходимо уметь по типу итератора узнавать тип элементов, на которые он указывает. 
	// Если итератор RandomIt принадлежит стандартному контейнеру (вектору, строке, множеству, словарю...), 
	// нижележащий тип можно получить с помощью выражения typename RandomIt::value_type. 
	// Таким образом, гарантируется, что создать вектор можно следующим образом:

	// 2. Создаем вектор, содержащий все элементы текущего диапазона
	vector<typename RandomIt::value_type> elements(range_begin, range_end);

	auto range_mid = elements.begin() + elements.size() / 2;

	MergeSort(elements.begin(), range_mid);
	MergeSort(range_mid, elements.end());
	merge(elements.begin(), range_mid, range_mid, elements.end(), range_begin);
	// Merge(elements, range_begin, range_mid, range_end);
}

// Реализация соритровки слиянием с разбиением на 2 части
int main() {
	vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};

	MergeSort(v.begin(), v.end());
	for (int x : v) {		// 0 1 4 4 4 6 6 7
		cout << x << " ";
	} cout << endl;

	return 0;
}