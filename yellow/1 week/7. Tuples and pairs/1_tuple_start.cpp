#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

// Кортжеи
#include <tuple>
// Пары
#include <utility>

#include <iostream>
using namespace std;

struct Date {
	int year;
	string month;
	int day;

	Date(int y, string m, int d) : year(y), month(m), day(d) {}
}

// В новых стандартах C++ можно опустить громоздкое название возвращаемого типа функции GetRank, использовав ключевое слово auto:
// auto == tuple<const int&, const string&, const int&>
auto GetRank(const Date& date) {
  return tie(date.year, date.month, date.day);
}

bool operator<(const Date& lhs, const Date& rhs) {
	return GetRank(lhs) < GetRank(rhs);
}

int main() {
	// Знакомство с кортежами
	Date date1(2020, "June", 20);
	Date date2(2020, "January", 11);
	cout << Date{2017, "June", 8} < Date{2017, "January", 20} << endl;

	// Создание кортежа из трех полей
	// 1 способ
	tuple<int, string, bool> t(7, "C++", true);
	// 2 способ
	auto t1 = make_tuple(6, "C", false);
	// 3 способ (С++17, у меня C++14)
	tuple t(7, "C++", true);


	// Обращение к полям кортежа:
	// Читается это так - получить первый элемент кортежа t
	cout << get<1>(t) << endl; // C++

	// Прямо скажем, кортеж - не лучший вариант. Лучше использовать структуру
	// (!) Пара - частный случай кортежа, но чуть приятнее

	// Иницилизация пары
	// 1 способ
	pair<int, string> p(7, "C++");
	cout << p.first << " " << p.second << endl;
	
	// 2 способ 
	auto p = make_pair(5, "Java");
	cout << p.first << " " << p.second << endl;

	// 3 способ (C++17)
	pair p(6, "C");
	cout << p.first << " " << p.second << endl;

	// Новые возможности C++17
	// Итерирование по словарю
	map<int, string> mp = {{1, "first"}};
	for(const auto& [key, value] : mp) {
		cout << key << " " << value << endl;
	}


	return 0;
}