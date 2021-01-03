#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct student {
	string name;
	string surname;
	int day, month, year;
};

void PrintStr(const vector<student> students) {
	for(const auto& s : students) {
		cout << s.name << " " << s.surname << endl;
		cout << s.day << " " << s.month << " " << s.year << endl;
	}
}

int main() {
	int n;
	cin >> n;

	vector<student> students;
	string name, surname;
	int day, month, year;
	
	for(int i = 0; i < n; i++) {
		cin >> name >> surname >> day >> month >> year;
		students.push_back({
			name, surname, 
			day, month, year
		});
	}
	// PrintStr(students);

	int m;
	cin >> m;

	string request;
	int student_number;
	for(int i = 0; i < m; i++) {
		cin >> request >> student_number;
		--student_number;

		if(request == "name" && student_number >= 0 && student_number < n) {
			cout << students[student_number].name << " " 
				 << students[student_number].surname << endl;
		} else if(request == "date" && student_number >= 0 && student_number < n) {
			cout << students[student_number].day << "." 
				 << students[student_number].month << "." 
				 << students[student_number].year << endl;
		} else {
			cout << "bad request" << endl;
		}
	}

	return 0;
}