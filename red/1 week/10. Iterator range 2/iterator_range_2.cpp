#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

template <typename Iterator>
class IteratorRange {
private:
	Iterator first, last;

public:
	// Написали конструктор для помощи конструктору определить тип шаблона класса
	IteratorRange(Iterator f, Iterator l) 
		: first(f)
		, last(l) 
	{
	}

	Iterator begin() const {
		return first;
	}

	Iterator end() const {
		return last;
	}
};

// было (см. ниже)
// IteratorRange<typename Container::iterator> Head(Container& v, size_t top) {

template <typename Container>
// Написав auto в качестве типа возвращаемого значения функции, мы говорим компилятору: 
// Компилятор, найди в реализации функции команду return, посмотри, какой тип там возвращается, и подставь его сюда (за место auto). 
// И компилятор это делает за нас. 
// *Дописал decltype и universe ref для работы со всеми вариантами ссылок
decltype(auto) Head(Container&& v, size_t top) {
	// Инициируем вызов конструктора и компилятор за нас выведет тип итератора, с которым надо инстанцировать наш шаблон.
	return IteratorRange(
		v.begin(), next(v.begin(), min(top, v.size()))
	);
}

// Написали порождающую функцию для шаблона класса, подобно make_pair в стандартном шаблоне pair
template <typename Iterator>
IteratorRange<Iterator> MakeRange(Iterator begin, Iterator end) {
	return IteratorRange<Iterator>{begin, end};
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	for (int i = 0; i < 3; i++) {
		cout << v[i] << " ";
	} cout << endl;

	auto second_half = MakeRange(v.begin() + v.size() / 2, v.end());

	for (int x : second_half) {
		cout << x << " ";
	} cout << endl;

	// ++++++++++++++
	
	// В -std=c++17 можно писать так
	pair p(5, true);

	// Понимает тип в шаблоне класса благодаря написанному конструктору
	// IteratorRange<vector<int>::iterator> ir(v.begin() + v.size() / 2, v.end()); 	// Если бы не написали конструктор для шаблона класса IteratorRange
	IteratorRange ir(v.begin() + v.size() / 2, v.end());

	// ++++++++++++++

	set<int> s = {4, 3, 4, 7, 1, 2, 0};
	// Правило Мейерса - везде, где только можно, применяйте std::move,
	// если вам объект больше не нужен, т.е. вы передаете этот объект и больше он вам не нужен.
	for (int x : Head(std::move(s), 3)) {
		cout << x << " ";		// 0 1 2
	} cout << endl;

	deque<int> d = {4, 3, 4, 7, 1, 2, 0};
	for (int x : Head(d, 3)) {
		cout << x << " ";		// 4 3 4
	} cout << endl;

	// После модификации Head (замены на auto) теперь у нас сам компилятор выводит тип итератора, с которым нужно инстанцировать IteratorRange.
	const deque<int> cd = {4, 3, 4, 7, 1, 2, 0};
	for (int x : Head(cd, 3)) {
		cout << x << " ";		// 0 1 2
	} cout << endl;


	return 0;
}