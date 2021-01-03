#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Date {
private:
	int year, month, day;

public:
	// Date() {
	// 	year = month = day = 0;
	// }

	Date(int y, int m, int d) : year(y), month(m), day(d) {

    	// Проверки
		if(to_string(year).size() > 4) {
			string error = "Year value is invalid: " + to_string(year);
			throw runtime_error(error);
		}

    	if(month > 12 || month < 1) {
    		string error = "Month value is invalid: " + to_string(month);
			throw runtime_error(error);
    	}

    	if(day > 31 || day < 1) {
    		string error = "Day value is invalid: " + to_string(day);
			throw runtime_error(error);
    	}
	}

	int GetYear() const {
		return year;
	}

	int GetMonth() const {
		return month;
	}

	int GetDay() const {
		return day;
	}

	bool operator<(const Date& op2) const {
		// воспользуемся тем фактом, что векторы уже можно сравнивать на <:
  		// создадим вектор из года, месяца и дня для каждой даты и сравним их
  		return vector<int>{year, month, day} < vector<int>{op2.year, op2.month, op2.day};
		
  		// // 2 способ
		// if(year == op2.year) {
		// 	if(month == op2.month) {
		// 		return day < op2.day;
		// 	}

		// 	return month < op2.month;
		// }

		// return year < op2.year;
	}

	void EnsureSym(stringstream& stream, string& data) {
		if (stream) {
			if(stream.peek() != '-') {
				stringstream ss;

				ss << "Wrong date format: " + data;
				throw runtime_error(ss.str());
			}

			stream.ignore(1);
		}
	}

	friend istream& operator>>(istream& ss, Date& dt) {

		string data;
		ss >> data;

		istringstream date_stream(date);
		bool ok = true;

		int year;
		ok = ok && (date_stream >> year);
		ok = ok && (date_stream.peek() == '-');
		date_stream.ignore(1);

		int month;
		ok = ok && (date_stream >> month);
		ok = ok && (date_stream.peek() == '-');
		date_stream.ignore(1);

		int day;
		ok = ok && (date_stream >> day);
		ok = ok && date_stream.eof();

		if (!ok) {
			throw logic_error("Wrong date format: " + date);
		}

		dt = Date(year, month, day);

		return ss;
	}

	friend ostream& operator<<(ostream& stream, const Date& dt) {
		return stream << setw(4) << setfill('0') << dt.year << "-"
			   		  << setw(2) << setfill('0') << dt.month << "-"
			   		  << setw(2) << setfill('0') << dt.day << " ";

		// // 2 способ
  		// return stream << dt.year << ":" << dt.month << ":" << dt.day;
    }
};

// ----------------->

class Database {
private:
	map<Date, set<string>> events;

public:
	// Database() {
	// 	events[Date("0-0-0")] = {};
	// }

	Database(Date date, set<string> event) {
		events[date] = event;
	}

	void AddEvent(const Date& date, const string& event) {
		events[date].insert(event);
	}

	bool DeleteEvent(const Date& date, const string& event) {
		return events[date].erase(event);
	}

	int DeleteDate(const Date& date) {
		int res = events[date].size();
		events[date].clear();

		return res;
	}

	set<string> Find(const Date& date) const {
		if(events.count(date) > 0) {
			return events.at(date);
		}

		return {};
	}

	// оформить
	void Print() const {
		for(const auto& event : events) {
			for(const auto& item : event.second) {
				cout << event.first << " " << item << endl;

				// // 2 способ
				// cout << setw(4) << setfill('0') << event.first.GetYear() << "-"
				// 		 << setw(2) << setfill('0') << event.first.GetMonth() << "-"
				// 		 << setw(2) << setfill('0') << event.first.GetDay() << " ";
				// cout << item << endl;
			} 
		}
	}

	bool IsRequest(stringstream& stream) {
		if(stream.peek() == EOF) {
			return false;
		}

		return true;
	}

};


// ----------------->

int main() {
	try {
		Database database;
		string command;

		while (getline(cin, command)) {
			stringstream stream(command);

			// запрос
			string request;
			// дата
			Date date;
			// событие
			string event;

			// Распарсим строку
			stream >> request;
			if(!request.empty() && database.IsRequest(stream)) {
				stream >> date;

				if(database.IsRequest(stream)) {
					stream >> event;
				}
			}

			// Выбираем запрос
			if(request == "Add") {
				database.AddEvent(date, event);

			} else if(request == "Find") {
				// const set<string> events = database.Find(date);
				for(const auto& event : database.Find(date)) {
					cout << event << endl;
				}

			} else if(request == "Del") {
				if(!event.empty()) {
					if(database.DeleteEvent(date, event)) {
						cout << "Deleted successfully" << endl;
					} else {
						cout << "Event not found" << endl;
					}
				} else {
					int N = database.DeleteDate(date);
					cout << "Deleted " << N << " events" << endl;
				}

			} else if(request == "Print") {
				database.Print();

			} else if(!request.empty()) {
				throw logic_eror("Unknown command: " + request);
			}
		}

	} catch(const exception& ex) {
		cout << ex.what() << endl;
	}


	return 0;
}