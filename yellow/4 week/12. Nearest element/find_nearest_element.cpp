#include <bits/stdc++.h>

using namespace std;

// set<int>::const_iterator — тип итераторов для константного множества целых чисел
set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
	// Запрашиваем итератор на первый элемент, не меньший border;
	const auto first_not_less = numbers.lower_bound(border);

	// Если множество пусто или до первого элемента не меньше border нет элементов, то мы уже получили ответ
	if (first_not_less == numbers.begin()) {
		return first_not_less;
	}

	// Если элементов, не меньших border, нет и set не пуст, то достаточно взять итератор на последний элемент, меньший border
	const auto last_less = prev(first_not_less);
	if (first_not_less == numbers.end()) {
		return last_less;
	}

	// Разыменуем оба итератора-кандидата и выберем тот, чей элемент ближе к искомому
	const bool is_left = (border - *last_less <= *first_not_less - border);
	
	return is_left ? last_less : first_not_less;
}

int main() {
	set<int> numbers = {1, 4, 6};
	cout <<
	*FindNearestElement1(numbers, 0) << " " <<
	*FindNearestElement1(numbers, 3) << " " <<
	*FindNearestElement1(numbers, 5) << " " <<
	*FindNearestElement1(numbers, 6) << " " <<
	*FindNearestElement1(numbers, 100) << endl;	// 1 4 4 6 6

	set<int> empty_set;

	cout << (FindNearestElement1(empty_set, 8) == end(empty_set)) << endl;	// 1

	return 0;
}