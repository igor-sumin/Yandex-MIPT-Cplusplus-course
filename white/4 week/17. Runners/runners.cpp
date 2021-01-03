#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <vector>
#include <string>
#include <map>

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

ostream& operator<<(ostream& stream, const Duration& duration) {
	stream << setfill('0');
	stream << setw(2) << duration.hour << ":" 
		   << setw(2) << duration.min;

	return stream;
}

// Метод сначала принимает поток, в который будет производиться запись, далее идет объект, который мы хотим выводить
istream& operator>>(istream& stream, Duration& duration) {
	stream >> duration.hour;
	stream.ignore(1);
	stream >> duration.min;

	return stream;
}

Duration operator+(const Duration& lhs, const Duration& rhs) {
	return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

bool operator<(const Duration& lhs, const Duration& rhs) {
	if(lhs.hour == rhs.hour) {
		return (lhs.min < rhs.min);
	}

	return (lhs.hour < rhs.hour);
}

int main() {
	ifstream input("runner.txt");

	Duration worst;
	map<Duration, string> all;

	if(input) {
		Duration dur;
		string name;

		while(input >> dur >> name) {
			worst = min(worst, dur);

			// Поскольку ключи в словаре уникальны, а худшее время может быть не одно,
			// то благодаря +=, можно записать в словарь с одним ключом несколько значений
			all[dur] += (name + " ");
		}
	} else {
		cout << "error" << endl;
	}

	ofstream out("result.txt");
	// All runner:
	for(const auto& durationNames : all) {
		out << durationNames.first << "\t" << durationNames.second << endl; 
	}

	// Worst runner:
	cout << "Worst runner: " << all[worst] << endl;

	return 0;
}