#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <exception>

using namespace std;

struct Date {
	int year, month, day;
};

void EnsureNextSymbolAndSkip(stringstream& stream) {
	if(stream.peek() != '/') {
		// // сообщаем main, из которго мы вызвали ParseDate, что пошло что-то не так 
		// throw exception();

		stringstream ss;
		// stream.peek() приводит код следующего символа -> приведем к char то, что возвращает метод peek

		ss << "expected /, but has: " << char(stream.peek()) ;
		// Сообщим об ошибке, передав в нее строку ss
		// Метод str вернет из потока строку, которая в нем записана
		throw runtime_error(ss.str());
	}
	stream.ignore(1);
}

Date ParseDate(const string& s) {
	stringstream stream(s);

	Date date;

	// Существует метод peek, позволяющий посмотреть какой следующий символ идет в потоке
	// stream.peek(); 
	// Но вместо миллиона условий и отлова ошибок воспользуемся библиотекой исключений

	stream >> date.year;
	EnsureNextSymbolAndSkip(stream);
	stream >> date.month;
	EnsureNextSymbolAndSkip(stream);
	stream >> date.day;

	return date;
}

int main() {
	// Счиитаем Date
	string date_str = "2017/01/25";

	try {
		// Потенциально опасный код

		// Распарсим строку date_str
		Date date = ParseDate(date_str);
		cout << setw(2) << setfill('0') << date.day << '.'
			 << setw(2) << setfill('0') << date.month << '.'
			 << date.year << endl;

	} catch (exception& ex) {
		// Обработка ошибки
		// cout << "exception happens" << endl;

		// ex.what() возвращает текст ошибки
		cout << "exception happens: " << ex.what();
	}

	// Что будет, если разделитель будет другим?
	// Формат неправильный, нужно от него защититься

	return 0;
}