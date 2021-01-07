#include <bits/stdc++.h>
// #include <deque>

using namespace std;
	
// Не просто очередь 
// Дек - deque (double entered queue)
// (!) Елси нужен вектор с добавлением в начало или удалением из начала, используйте deque

int main() {
	// // Быстрые операции
	// d.push_back(x);
	// d.pop_back();	

	// d.push_front(x) - добавление в начало
	// d[i] - обращение по индексу

	// ...

	// Используем vector
	int n;
	cin >> n;
	vector<int> v(n);
	// (n - 1)! итераций цикла
	while(!v.empty()) {
		// удалили первый элемент вектора, далее все подвинули
		v.erase(v.begin());
	} cout << "Empty!" << endl;

	// Используем deque
	int n;
	cin >> n;
	deque<int> v(n);
	while(!v.empty()) {
		v.pop_front();
		// v.erase(v.begin());
	} cout << "Empty!" << endl;

	// Если возможно, используй vector


	return 0;
}