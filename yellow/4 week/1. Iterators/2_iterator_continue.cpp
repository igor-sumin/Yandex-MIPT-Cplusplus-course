#include <bits/stdc++.h>

using namespace std;

struct Lang {
	string name;
	int age;
};

int main() {
	// Типы, которые указывают на позицию в контейнере называютс итераторами
	// операция * над итераторами называется разыменованием итератора

	vector<Lang> langs = {
		{"Python", 26}, {"C++", 34}, {"C", 45}, {"Java", 22}, {"C#", 17}
	};

	auto result = find_if(langs.begin(), langs.end(), [](const Lang& lang) {
		return lang.name[0] == 'C';
	});

	// Конец диапазона (Если не нашли нужный нам объект)
	if(result == langs.end()) {
		cout << "not found" << endl;
		exit(1);
	}

	// Обращение к полю, найденного объекта
	// *result - это ссылка, на тот элемент, который нашли
	// 1 способ 
	cout << (*result).age << endl;

	// 2 способ ('->' означает обращение к полю объекта)
	cout << result->age << endl;

	// begin() указывает на нулевой объект контейнера
	cout << langs.begin()->name << ", " << langs.begin()->age << endl;	// Python, 26

	return 0;
}