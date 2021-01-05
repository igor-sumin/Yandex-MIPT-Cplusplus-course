#include <bits/stdc++.h>
using namespace std;

// Предварительное объявление шаблонных функций:
// Для простых типов
template<typename T> T Sqr(T value);
// Для вектора
template<typename T> vector<T> Sqr(const vector<T>& value);
// Для словаря
template<typename K, typename V> map<K, V> Sqr(const map<K, V>& value);
// Для пары
template<typename K, typename V> pair<K, V> Sqr(const pair<K, V>& value);


// Объявляем шаблонные функции
// Для простых типов
template<typename T>
T Sqr(T value) {
 	return value * value;
}

// Для вектора
template<typename T>
vector<T> Sqr(const vector<T>& value) {
	vector<T> result;
	for (const T& x : value) {
		// Поскольку вызываем Sqr, то перегружать operator* не требуется
		
		// Здесь важно, что вместо x * x вызывается функция Sqr:
    	// это позволяет возводить в квадрат составные объекты
		result.push_back(Sqr(x));
	}

	return result;
}

// Для словаря
template<typename K, typename V>
map<K, V> Sqr(const map<K, V>& value) {
	map<K, V> result;
	for (const auto& element : value) {
		result[element.first] = Sqr(element.second);
	}

	return result;
}

// Для пары
template<typename K, typename V>
pair<K, V> Sqr(const pair<K, V>& value) {
 	return {Sqr(value.first), Sqr(value.second)};
}

int main() {
	// Пример вызова функции
	vector<int> v = {1, 2, 3};

	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = { 
		{4, {2, 2}}, {7, {4, 3}} 
	};

	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	
	// Вывод
	// vector: 1 4 9

	// map of pairs:
	// 4 4 4
	// 7 16 9

	const vector<int> a{1,1,1}, b{2,2,2};
	for(auto& v:Sqr(a,b)) 
		cout<<v<<' ';   

	return 0;
}