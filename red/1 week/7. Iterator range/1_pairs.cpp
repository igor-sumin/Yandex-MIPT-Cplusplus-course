#include <iostream>
#include <vector>
using namespace std;

struct pair_of_string_and_int {
	string first;
	int second;
};

struct pair_of_bool_and_char {
	bool first;
	char second;
};

// Шаблон класса - пара
template <class T, class U>
struct Pair {
	T first;
	U second;
};

int main() {
	pair_of_string_and_int si;
	si.first = "hello";
	si.second = 5;

	pair_of_string_and_int si2;
	si.first = true;
	si.second = 'z';

	// Создание типа из шаблона класса называется инстанцированием
	Pair<string, int> p;
	// Pair<bool, char> - это класс, самостоятельный тип
	Pair<bool, char> p2;

	return 0;
}