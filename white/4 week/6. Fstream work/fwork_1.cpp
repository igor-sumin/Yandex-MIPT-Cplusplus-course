#include <iostream>
#include <fstream>

#include <vector>
#include <string>

using namespace std;

int main() {
	// Чтобы считать содержимое файла следует объявить экземпляр класса ifstream
	ifstream input("input.txt");

	if(input) {
		// Можно создать строковую переменную, в которую будет записан результат чтения из файла
		string line;
		while(getline(input, line)) {
			// Функция getline, на самом деле, считывает данные до некоторого разделителя, 
			// причем по умолчанию до символа перевода строки, который в считанную строку не попадает.
			cout << line << endl;
		}
	} else {
		cout << "error" << endl;
	}

	return 0;
}