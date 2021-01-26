#include <iostream>
#include <vector>

using namespace std;

// Реализации Head:

// 1 способ - простой вариант 
// Возвращать из функции Head копию префикса вектора, по которому мы можем пройтись.
template <typename T>
vector<T> Head1(vector<T>& v, size_t top) {
	return {
		// У std::next второй параметр - количество элементов для продвижения
		v.begin(), next(v.begin(), min(top, v.size()))
	};
}

// 2 способ - лучше
// Мы можем возвращать пару итераторов и итерироваться по ним. 
template <typename Iterator>
struct IteratorRange {
	Iterator first, last;

	// Чтобы по объекту класса можно было итерироваться с помощью цикла for, этот класс должен иметь методы begin и end. 
	// И при этом эти методы должны возвращать итераторы на начало и конец той коллекции, которую объект этого класса представляет.
	Iterator begin() const {
		return first;
	}

	Iterator end() const {
		return last;
	}
};

// Собственно, из функции Head вместо копии вектора возвращать лишь пару итераторов на вектор v и итерироваться в цикле по ним
template <typename T>
// vector<T>::iterator - итератор вектора типа T
// IteratorRange - шаблон класса
// IteratorRange<typename vector<T>::iterator> - класс
IteratorRange<typename vector<T>::iterator> Head2(vector<T>& v, size_t top) {
	return {
		// У std::next второй параметр - количество элементов для продвижения
		v.begin(), next(v.begin(), min(top, v.size()))
	};
}

template <typename T>
// Проинстацировали it для работы с функцией и шаблоном итератора типа T
size_t RangeSize(IteratorRange<T> it) {
	// iterator - iterator = size_t (distance)
	return it.end() - it.begin();
}

// То есть вот эта важная вещь, которую вы тоже должны усвоить, что шаблон класса — это шаблон, а класс — это та вещь, которая из шаблона получается. 
// Нельзя использовать просто шаблон без инстанцирования в том месте, где язык ожидает увидить тип.
int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	for (int i = 0; i < 3; i++) {
		cout << v[i] << " ";
	} cout << endl;

	// Универсальнее, чем цикл выше
	for (int x : Head1(v, 3)) {
		cout << x << " ";
	} cout << endl;

	// Покажем работоспособность 2ого способа
	for (int& x : Head2(v, 3)) {
		++x;
	} 

	for (int x : v) {
		cout << x << " ";		// 2 3 4 4 5
	} cout << endl;

	cout << RangeSize(Head2(v, 3)) << endl;

	return 0;
}