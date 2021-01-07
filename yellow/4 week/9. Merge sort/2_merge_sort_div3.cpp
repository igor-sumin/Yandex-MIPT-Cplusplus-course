#include <bits/stdc++.h>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	if(range_end - range_begin < 3)	{
		return;
	}
	// 2. Создаем вектор, содержащий все элементы текущего диапазона
	vector<typename RandomIt::value_type> elements(range_begin, range_end);
	
	// 3. Разбиваем вектор на три равные части
	auto range_mid_1 = elements.begin() + elements.size() / 3;
	auto range_mid_2 = range_mid_1 + elements.size() / 3;

	// 4. Вызываем функцию MergeSort от каждой трети вектора
	MergeSort(elements.begin(), range_mid_1);
	MergeSort(range_mid_1, range_mid_2);
	MergeSort(range_mid_2, elements.end());

	// 5. С помощью алгоритма merge cливаем первые две трети во временный вектор
	vector<typename RandomIt::value_type> dop;
	merge(elements.begin(), range_mid_1, range_mid_1, range_mid_2, back_inserter(dop));
	// 6. С помощью алгоритма merge сливаем отсортированные части в исходный диапазон
	merge(dop.begin(), dop.end(), range_mid_2, elements.end(), range_begin);
}

// Реализация сразбиением на 3 части
int main() {
	vector<int> v = {9, 6, 4, 7, 6, 4, 4, 0, 1, 5};	// 0 1 4 4 4 5 6 6 7

	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	} cout << endl;

	return 0;
}