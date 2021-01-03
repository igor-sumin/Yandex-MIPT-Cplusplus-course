#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

//-> 1 способ - мой
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
	    	// получить имя и фамилию по состоянию на конец года year

	  		if(tPerson.empty()) {
	  			return ("Incognito");
	  		}

	  		auto dop = tPerson.begin(); dop++;
	  		auto lop = tPerson.end(); lop--;
	  		auto it = tPerson.begin();

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

		void PrintMap(int year, const map<int, info>& tPerson) {
			// Вывод словаря
			cout << "Prishel " << year << ": " << endl;
			for(auto s : tPerson) {
				cout << "Mi v " << s.first << ": " << endl;
				cout << s.second.name << " - " << s.second.changed_name << endl;
				cout << s.second.surname << " - " << s.second.changed_surname << endl;
			} cout << endl;
		}

		string GetFullNameWithHistory(int year) {
			// Получить все имена и фамилии по состоянию на конец года year
			
			// Записываем в res результат
			string res;

			if(tPerson.empty()) {
	  			return ("Incognito\n");
	  		}

	  		auto it = tPerson.begin();
	  		auto dop = tPerson.begin(); dop++;
	  		auto lop = tPerson.end(); lop--;

	  		if(dop == tPerson.end()) {
	  			return(PrintOf(year));
			} else if(it->first >= year) {
  				return(PrintOf(year));
  			}

			// Идем вверх и считываем имена с приоритетом
			map<int, info>::iterator next = tPerson.lower_bound(year);
			if(next == tPerson.end()) {
				next = lop;
			} else if(next->first > year) {
				next--;
			}

			auto cur = next--;
			vector<string> skob;

			auto tek = cur->first;
			for(bool f = false;cur != tPerson.begin(); cur--, next--) {
				if(!f) {
					if(!tPerson[cur->first].name.empty()) {
						skob.push_back(tPerson[cur->first].name);
						f = true;
					}
				}
				if(tPerson[next->first].name != tPerson[tek].name && tPerson[next->first].changed_name == 1) {
					tek = next->first;
					skob.push_back(tPerson[next->first].name);
				}
			}

			bool g1 = false;
			if(!skob.empty()) {
				res += skob[0] + " ";
				if(skob.size() != 1) {
					res += "(";
					for(int i = 1; i < skob.size(); i++) {
						if(skob[i] == skob[skob.size() - 1]) {
							res += skob[i];
							break;
						}
						res += skob[i] + ", ";
					} res += ") ";
				}
			} else {
				g1 = true;
			}


			// Идем вверх и считываем фамилии с приоритетом
			map<int, info>::iterator next1 = tPerson.lower_bound(year);
			if(next1 == tPerson.end()) {
				next1 = lop;
			} else if(next1->first > year) {
				next1--;
			}

			auto cur1 = next1--;
			vector<string> skob1;

			auto tek1 = cur1->first;
			for(bool f = false;cur1 != tPerson.begin(); cur1--, next1--) {
				if(!f) {
					if(!tPerson[cur1->first].surname.empty()) {
						skob1.push_back(tPerson[cur1->first].surname);
						f = true;
					}
				}
				if(tPerson[next1->first].surname != tPerson[tek1].surname && tPerson[next1->first].changed_surname == 1) {
					tek1 = next1->first;
					skob1.push_back(tPerson[next1->first].surname);
				}
			}

			bool g2 = false;
			if(!skob1.empty()) {
				res += skob1[0];
				if(skob1.size() != 1) {
					res += " (";
					for(int i = 1; i < skob1.size(); i++) {
						if(skob1[i] == skob1[skob1.size() - 1]) {
							res += skob1[i];
							break;
						}
						res += skob1[i] + ", ";
					} res += ")";
				}
			} else {
				g2 = true;
			}

			if(g1 && g2) {
				return "Incognito";
			} else if(g2) {
				return (res + "with unknown last name");
			} else if(g1) {
				return (res + " with unknown first name");
			} else {
				return res;
			}

	  		return "ERROR\n";
		}
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;

	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;

	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;

	return 0;
}
