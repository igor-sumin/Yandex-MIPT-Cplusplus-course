#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

//-> 1 способ - Мой
class Person {
	private:
		struct info {
			string name;
			string surname;
			// true - вызвали в main метод изменения имени или фамилии
			// false - изменили имя и фамилию в методе класса Person
			bool changed_name;
			bool changed_surname;
		};

		map<int, info> tPerson;

	public:
	  	void ChangeFirstName(int year, const string& first_name) {
	    	// добавить факт изменения имени на first_name в год year
	  		tPerson[year].name = first_name;
	  		tPerson[year].changed_name = true;

	  		// Идем вверх и ищем фамилию
	  		map<int, info>::iterator rop = tPerson.lower_bound(year);
	  		while(tPerson[year].surname.empty()) {
	  			if(!tPerson[rop->first].surname.empty()) {
	  				tPerson[year].surname = tPerson[rop->first].surname;
	  			}
	  			if(rop == tPerson.begin()) {
	  				break;
	  			}
	  			rop--;
	  		}

	  		// Идем вниз и ищем фамилию с приоритетом 1
	  		for(auto chop = tPerson.lower_bound(year), fop = chop++; fop != tPerson.end(), chop != tPerson.end();  chop++, fop++) {
	  			if(tPerson[chop->first].changed_name == 0) {
	  				tPerson[chop->first].name = tPerson[fop->first].name;
	  				tPerson[chop->first].changed_name = false;
	  			}
	  		}
	  	}
	  	void ChangeLastName(int year, const string& last_name) {
	    	// добавить факт изменения фамилии на last_name в год year
	    	tPerson[year].surname = last_name;
	  		tPerson[year].changed_surname = true;

	  		map<int, info>::iterator rop = tPerson.lower_bound(year); 
	  		while(tPerson[year].name.empty()) {
	  			if(!tPerson[rop->first].name.empty()) {
	  				tPerson[year].name = tPerson[rop->first].name;
	  			}
	  			if(rop == tPerson.begin()) {
	  				break;
	  			}
	  			rop--;
	  		}

	  		// Идем вниз и ищем фамилию с приоритетом 1
	  		for(auto chop = tPerson.lower_bound(year), fop = chop++; fop != tPerson.end(), chop != tPerson.end();  chop++, fop++) {
	  			if(tPerson[chop->first].changed_surname == 0) {
	  				tPerson[chop->first].surname = tPerson[fop->first].surname;
	  				tPerson[chop->first].changed_surname = false;
	  			}
	  		}
		}

		void PrintMap(int year, const map<int, info>& tPerson) {
			// Вывод словаря
			cout << "Prishel " << year << ": " << endl;
			for(auto s : tPerson) {
				cout << "Mi v " << s.first << ": " << endl;
				cout << s.second.name << " - " << s.second.changed_name << endl;
				cout << s.second.surname << " - " << s.second.changed_surname << endl;
			} cout << endl;
		}

	  	string PrintOf(const int& it) {
	  		if(tPerson[it].name.empty() && tPerson[it].surname.empty()) {
				return ("Incognito");
			} else if(tPerson[it].name.empty()) {
				return (tPerson[it].surname + " with unknown first name");
			} else if(tPerson[it].surname.empty()) {
				return (tPerson[it].name + " with unknown last name");
			} else {
				return (tPerson[it].name + " " + tPerson[it].surname);
			}
	  	}

	  	string GetFullName(int year) {
	    	// Получить имя и фамилию по состоянию на конец года year

	  		if(tPerson.empty()) {
	  			return ("Incognito");
	  		}

	  		auto dop = tPerson.begin(); dop++;
	  		auto lop = tPerson.end(); lop--;
	  		auto it = tPerson.begin();

			// PrintOf(year, tPerson);
			
			if(dop == tPerson.end()) {
				return(PrintOf(year));
			}

	  		for(; it != tPerson.end(), dop != tPerson.end(); it++, dop++) {
	  			if(it->first >= year) {
	  				return(PrintOf(year));
	  			}
	  			if(lop->first < year) {
	  				return(PrintOf(lop->first));
	  			}
	  			if(it->first < year && year < dop->first) {
	  				return(PrintOf(it->first));
	  			}
	  			if(dop->first == year) {
	  				return(PrintOf(year));
	  			}
	  		}

			return "ERROR\n";
		}
};

int main() {
	Person person;
	
	person.ChangeLastName(3, "3_2nd");
	person.ChangeLastName(6, "6_2nd");
	
	for (int year : {3, 4, 5, 6}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(-1, "-1_1st");
	person.ChangeFirstName(2, "2_1st");

	for (int year : {-1, 0, 1, 2, 3, 6}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(-2, "-2_1st");
	person.ChangeLastName(7, "7_2nd");

	for (int year : {-3, -2, -1, 0, 1, 2, 3, 6, 7, 8}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}
