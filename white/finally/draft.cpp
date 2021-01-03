if(command == "Add") {

} else if(command == "Del") {
// ?
} else if(command == "Find") {

} else if(command == "Print") {

} else {

}

void ParsingDate(stringstream& ) {

}

stream >> year;
stream >> def1;
EnsureNextSymbolAndSkip(stream);
stream >> month;
stream >> def2;
EnsureNextSymbolAndSkip(stream);
stream >> day;

void EnsureNextSymbolAndSkip(stringstream& stream) {
if(stream.peek() != '-') {
stringstream ss;
ss << "expected "-", but has: " << char(stream.peek());

throw runtime_error(ss.str());
}
stream.ignore(1);
}

// stringstream stream(data);
// char def1, def2;

// // Распарсим строку
//    if (stream) {
// 	stream >> year >> def1 >> month >> def2 >> day;

// 	// Проверки
// 	if (def1 != '-' || def2 != '-') {
// 		stringstream ss;
// 		ss << "expected \"-\", but has: " << char(def1) << " and " << char(def2);

// 		throw runtime_error(ss.str());
//           } 

//           if (stream.peek() != EOF) {
// 		throw "not EOF";
// 	}

//   	} else {
//   		throw "not path";
//   	}

try {
Date data;
cin >> data;
cout << data << endl;

} catch(const exception& ex) {
cout << ex.what() << endl;
}

// Проверки
if (def1 != '-' || def2 != '-') {
stringstream ss;
ss << "expected \"-\", but has: " << char(def1) << " and " << char(def2);

throw runtime_error(ss.str());
} else if (stream.peek() != EOF) {
stringstream ss;
ss << "expected EOF , but has: " << char(stream.peek());

throw runtime_error(ss.str());
} else {
dt = Date(y, m, d);
}

cout << request << "_" << endl;
cout << date << "_" << endl
cout << event << "_" << endl;

Тесты:
Add 1-2-3 ev1
Add 1-2-3 ev2
Add 1-2-4 ev4
Add 1-2-4 ev3
Del 1-2-3

stringstream ss;
// ss << "expected \"-\", but has: " << char(def1) << " and " << char(def2);
ss << "Wrong date format: " << char(def1);

throw runtime_error(ss.str());

Add 0-1-2 event1
Add 1-2-3 event2
Find 0-1-2

Del 0-1-2
Print
Del 1-2-3 event2
Del 1-2-3 event2

if(events.empty()) {
	cout << "events is empty" << endl;
} else {
	for(const auto& event : events) {
		if(event.second.size() > 0) {
			cout << setw(4) << setfill('0') << event.first.GetYear() << "-"
				 << setw(2) << setfill('0') << event.first.GetMonth() << "-"
				 << setw(2) << setfill('0') << event.first.GetDay() << " ";

			for(const auto& item : event.second) {
				cout << item << " ";
			} cout << endl;
		} else {
			continue;
		}
	}
}

Input:
Add 0-1-2 event1
Add 1-2-3 event2
Find 0-1-2

Del 0-1-2
Print
Del 1-2-3 event2
Del 1-2-3 event2

Your output:
event1
Unknown command: 
Deleted 1 events
0001-02-03 event2 
Deleted successfully
Event not found

Correct output:
event1
Deleted 1 events
0001-02-03 event2
Deleted successfully
Event not found

Failed case #3/34: (Wrong answer)

Input:
Add qwerty qwerty

Your output:
Wrong date format: 

Correct output:
Wrong date format: qwerty

if(!(ss >> y)) {
	ss1 << "Wrong1 date format: " + data;
	throw runtime_error(ss1.str());
}
ss >> def1;
if(def1 != '-') {
	ss1 << "Wrong2 date format: " + def1;
	throw runtime_error(ss1.str());
}
if(!(ss >> m)) {
	ss1 << "Wrong1 date format: " + data;
	throw runtime_error(ss1.str());
}
ss >> def2;
if(def2 != '-') {
	ss1 << "Wrong3 date format: " + def2;
	throw runtime_error(ss1.str());
}
if(!(ss >> d)) {
	ss1 << "Wrong1 date format: " + data;
	throw runtime_error(ss1.str());
}
ss >> c;
if(c == ' ' || c == EOF) {
	ss1 << "Wrong1 date format: " + c;
	throw runtime_error(ss1.str());
}

// cout << y << m << d << endl;
// cout << c << endl;

// if(d == m == -1) {
// 	ss1 << "Wrong1 date format: " + data;
// 	throw runtime_error(ss1.str());
// } else if(def1 != '-') {
// 	ss1 << "Wrong2 date format: " + def1;
// 	throw runtime_error(ss1.str());
// } else if(def2 != '-') {
// 	ss1 << "Wrong3 date format: " + def2;
// 	throw runtime_error(ss1.str());
// } else if(c == ' ' || c == EOF) {
// 	cout << "hi" << endl;
// } else {
// 	dt = Date(y, m, d);
// }

// Распарсим строку
		// stream >> y >> def1 >> m >> def2 >> d;
		// c = stream.peek();

		// // Проверки
		// if (def1 != '-') {
		// 	string error = "Wrong date format: " + def1;
		// 	throw runtime_error(error);
  //       } else if(def2 != '-') {
		// 	string error = "Wrong date format: " + def2;
		// 	throw runtime_error(error);
  //       }

  //       if (c == EOF || c == ' ') {
  //       	dt = Date(y, m, d);
  //       } else {
  //       	string error = "Expected EOF, but had: " + c;
		// 	throw runtime_error(error);
  //       }



// ss >> def1;
// if(def1 != '-') {
// 	ss1 << "Wrong date format: " + def1;
// 	throw runtime_error(ss1.str());
// }

Failed case #1/34: (Wrong answer)

Input:
Add 0-1-2 event1
Add 1-2-3 event2
Find 0-1-2

Del 0-1-2
Print
Del 1-2-3 event2
Del 1-2-3 event2

Your output:
event1
Deleted 1 events
0001-02-03 event2 
Deleted successfully
Event not found

Correct output:
event1
Deleted 1 events
0001-02-03 event2
Deleted successfully
Event not found

Add 1-1-1 task
Add -2-1-1 task
Add 03-01-01 task
Add +4-1-1 task
Add 1-+6-1 task
Add 1-1-+7 task

Add f8-1-1 task
Add 9f-1-1 task
Add 1-11f-1 task
Add 1-f12-1 task
Add 1-1-f13 task!
Add 1-1-14f task
Add --15-1-1 task
Add 1---2-1 task
Add 1-1---17 task
Add 1-1- task
Add 1--1 task
Add --111 task
Add 1---+++1 task
Add --++1 task
Add 1-1-f task
Del foo

int y, m, d;
y = d = m = -1;
char def1, def2, c;

string data;
stream >> data;
stringstream ss(data);
stringstream ss1;

if(!(ss >> y)) {
	ss1 << "Wrong date format: " + data;
	throw runtime_error(ss1.str());
}

dt.EnsureSym(ss);

if(!(ss >> m)) {
	ss1 << "Wrong date format: " + data;
	throw runtime_error(ss1.str());
}

dt.EnsureSym(ss);

if(!(ss >> d)) {
	ss1 << "Wrong date format: " + data;
	throw runtime_error(ss1.str());
}

ss >> c;
if(c == ' ' || c == EOF) {
	ss1 << "Wrong date format: " + c;
	throw runtime_error(ss1.str());
}

dt = Date(y, m, d);

if(count(data.begin(), data.end(), '-') > 2) {
int year, month, day;
stream >> year;
EnsureSym(stream);
	


for(int i = 0; i < data.size(); i++) {
	stream >> x;
	EnsureSym(stream);

}


} else {
stringstream ss;

ss << "Wrong1 date format: " + data;
throw runtime_error(ss1.str());
}

stream >> year;
dt.EnsureSym(stream, data);
stream >> month;
dt.EnsureSym(stream, data);
if(stream.peek() == '-') {
	if((stream >> day)) {
		cout << day << endl;
	} else {
		stringstream ss;

		ss << "Wrong date format: " + data;
		throw runtime_error(ss.str()); 
	}
} else {
	if((stream >> day)) {
		cout << day << endl;
	} else {
		stringstream ss;

		ss << "Wrong date format: " + data;
		throw runtime_error(ss.str()); 
	}
}
char c = stream.peek();
cout << c << endl;

friend istream& operator>>(istream& ss, Date& dt) {

	string data;
	ss >> data;

	stringstream stream(data);
	int year, month, day;

	if(2 > count(data.begin(), data.end(), '-') > 5 || count_if(data.begin(), data.end(), [](char i) { return isalpha(i); }) > 0) {
		stringstream ss;

		ss << "Wrong date format: " + data;
		throw runtime_error(ss.str());
	}

	stream >> year;
	dt.EnsureSym(stream, data);
	stream >> month;
	dt.EnsureSym(stream, data);
	stream >> day;
	char c = stream.peek();

	// Если не конец - ошибка
	if(c != EOF) {
		stringstream ss;

		ss << "Wrong date format: " + data;
		throw runtime_error(ss.str()); 
	}

	dt = Date(year, month, day);

	return ss;
}

// Мой способ
stringstream stream(data);
int year, month, day;

if(2 > count(data.begin(), data.end(), '-') > 5 || count_if(data.begin(), data.end(), [](char i) { return isalpha(i); }) > 0) {
	stringstream ss;

	ss << "Wrong date format: " + data;
	throw runtime_error(ss.str());
}

stream >> year;
dt.EnsureSym(stream, data);
stream >> month;
dt.EnsureSym(stream, data);

if(stream.peek() == '-') {
	if((stream >> day)) {
		;
	} else {
		stringstream ss;

		ss << "Wrong date format: " + data;
		throw runtime_error(ss.str()); 
	}
} else {
	if((stream >> day)) {
		;
	} else {
		stringstream ss;

		ss << "Wrong date format: " + data;
		throw runtime_error(ss.str()); 
	}
}
char c = stream.peek();

// Если не конец - ошибка
if(c != EOF) {
	stringstream ss;

	ss << "Wrong date format: " + data;
	throw runtime_error(ss.str()); 
}

dt = Date(year, month, day);