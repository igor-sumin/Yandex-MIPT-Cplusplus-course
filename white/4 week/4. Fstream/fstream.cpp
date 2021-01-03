#include <iostream>
#include <fstream>
#include <string>

// (!) Важно понимать:
// ifstream - для чтения
// ofstream - для записи
// fstream  - для чтения/записи

using namespace std;

// Задача №1: считать все данные из файла hello.txt
void task1() {
	const string path = "hello.txt";
	ifstream input(path);

	if(input) {	// input.is_open() 
		string line;	
		// выводим все строки файла по отдельности
		while(getline(input, line)) {
			cout << line << endl;
		}
	} else {
		cout << "error1" << endl;
	}

	cout << endl;
}

// Задача №2: Положить из файла date.txt данные в месяц, год, число
void task2() {
	const string path = "date.txt";
	ifstream input(path);
	string year, month, day;

	if(input) {
		// Нужно считать файл таким образом, чтобы соответствующие части файла попали в нужную переменную. 
		// Воспользуемся функцией getline и укажем разделитель

		// Третьим параметром указываем до какого знака считывать данные
		getline(input, day, '-');
		getline(input, month, '-');
		getline(input, year, '-');
	} else {
		cout << "error2" << endl;
	}

	cout << day << " " << month << " " << year << endl;
}

// Другая реализация задачи №2
void task2_dop() {
	const string path = "date.txt";
	// Решим ту же самую задачу с помощью оператора чтения из потока (>>).
	// Записывать считанные данные будем в переменные типа int.
	ifstream input(path);
	int year, month, day;

	if(input) {
		input >> day;
		// После того, как из потока будет считан год, следующим символом будет «минус»,
		// от которого нужно избавиться

		// Это можно сделать с помощью метода ignore, который принимает целое число — сколько символов нужно пропустить. 
		// Аналогично считываются месяц и день. Получается такой же результат
		input.ignore(1);
		input >> month;
		input.ignore(1);
		input >> year;
		input.ignore(1);

	} else {
		cout << "error2.1" << endl;
	}

	cout << day << " " << month << " " << year << endl;
}

// Задача №3: Запись данных в файл output.txt
void task3() {
	const string path = "output.txt";

	// Следует отметить, что при каждом запустке программы файл записывается заново, 
	// то есть его содержимое удалялось и запись начиналась заново.
	// Для того, чтобы открыть файл в режиме дозаписи, нужно передать специальный флажок ios::app
	
	// ios::app - (сокр. append) позволяет дописывать данные в файл
	ofstream output(path, ios::app);
	output << "hello, world!" << endl;

	ifstream input(path);
	if(input) {
		string line;
		while(getline(input, line)) {
			cout << line << endl;
		}
	} else {
		cout << "error3" << endl;
	}

	// То, каким методом пользоваться, зависит от ситуации. 
	// Иногда бывает удобнее сперва считать всю строку целиком.
}

int main() {
	task1();
	task2();
	task2_dop();
	task3();
	return 0;
}