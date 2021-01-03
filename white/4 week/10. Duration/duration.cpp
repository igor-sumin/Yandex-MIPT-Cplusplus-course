#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Duration {
	int hour;
	int min;
	Duration(int h = 0, int m = 0) {
		int total = h * 60 + m;
		hour = total / 60;
		min = total % 60;
	}
};

Duration ReadDuration(istream& stream) {
	int h = 0;
	int m = 0;

	// считываем часы
	stream >> h;
	// игнорируем разделитель
	stream.ignore(1);
	// считываем минуты
	stream >> m;

	return Duration(h, m);
}

void PrintDuration(ostream& stream, const Duration& duration) {
	stream << setfill('0');
	// установим ширину поля для часов и выведем содержимое структуры с разделителем
	stream << setw(2) << duration.hour << ":" 
		   << setw(2) << duration.min;

}

// Переопределяем оператор вывода в поток
// Метод сначала принимает поток, в который будет производиться запись, далее идет объект, который мы хотим выводить
ostream& operator<<(ostream& stream, const Duration& duration) {
	stream << setfill('0');
	stream << setw(2) << duration.hour << ":" 
		   << setw(2) << duration.min;

	// Возвращаем поток, в который делаем запись
	// (!) Мы возвращаем ссылку на поток, чтобы иметь возможность производить цепочки операций, то есть выводить несколько значений
	return stream;
}

// Переопределяем оператор ввода из потока
// Метод сначала принимает поток, в который будет производиться запись, далее идет объект, который мы хотим выводить
istream& operator>>(istream& stream, Duration& duration) {
	// считываем часы
	stream >> duration.hour;
	// игнорируем разделитель
	stream.ignore(1);
	// считываем минуты
	stream >> duration.min;

	return stream;
}

// ----->

Duration operator+(const Duration& lhs, const Duration& rhs) {
	return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

void PrintVector(const vector<Duration>& durs) {
	for(const auto& s : durs) {
		cout << s << " ";
	} cout << endl;
}

bool operator<(const Duration& lhs, const Duration& rhs) {
	if(lhs.hour == rhs.hour) {
		return (lhs.min < rhs.min);
	}

	return (lhs.hour < rhs.hour);
}

int main() {
	// завели строковый поток и иницилизировали его 
	stringstream dur_ss("01:50");

	// Введем значения для dur1
	
	// 1 способ
	// Завели структуру
	// Duration dur1 = ReadDuration(dur_ss);

	// 2 способ
	// Иницилизировали значением по умолчанию -> улучшим, написав конструктор по умолчанию
	// Duration dur2 {0, 0};
	Duration dur2;
	// Сделали считывание с помощью оператора ввода
	dur_ss >> dur2;

	// Напечатаем содержимое dur1 в поток вывода cout

	// 1 способ
	// PrintDuration(cout, dur1);

	// 2 способ
	// Вывели содержимое с помощью оператора вывода
	cout << dur2 << endl;

	// ---->

	// Перегрузим сложение, для того, чтобы была возможность складывать интервалы
	Duration dur3 = {0, 5};
	cout << dur2 + dur3 << endl;

	// Создадим вектор интервалов и отсортируем интервалы по возрастанию
	Duration dur1 = dur2 + dur3;
	vector<Duration> vec {
		dur1, dur3, dur2 
	};
	PrintVector(vec);

	// для вызова алгоритма сортировки нам требуется перегрузить оператор<, чтобы сравнивать элементы вектора
	sort(vec.begin(), vec.end());
	PrintVector(vec);

	return 0;
}