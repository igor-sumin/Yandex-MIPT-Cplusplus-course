#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <tuple>
#include <utility>

#include <iostream>
using namespace std;

class Cities {
private:
	map<string, string> city_to_country;
	set<string> ambiguous_cities;

public:
	tuple<bool, string> FindCountry(const string& city) const {
		if(city_to_country.count(city) == 1) {
			// operator[] не подходит, так как у нас константный метод - используем метод at()
			// make_tuple позволяет создать кортеж из заданных значений
			return make_tuple(true, city_to_country.at(city));
		} else if(ambiguous_cities.count(city) == 1) {
			return make_tuple(false, "Ambiguous");
		} else {
			return make_tuple(false, "Not exist");
		}
	}
};

int main() {
	Cities cities;

	auto t = cities.FindCountry("Volgograd");
	cout << get<1>(t) << endl;	// Not excist

	// Присвоим значения из FindCountry в tie
	// tuple<bool&, string&> - tie изменит значения, лежащие в succes, message
	bool success;
	string message;
	tie(success, message) = cities.FindCountry("NN");
	cout << success << " " << message << endl;		// 0 Not exist

	// -std =c++17
	auto [success1, message1] = cities.FindCountry("Moscow");
	cout << success1 << " " << message1 << endl;	// 0 Not exist

	// Итак, если вы хотите вернуть несколько значений из функции или из метода, используйте 
	// кортеж. А если вы хотите сохранить этот кортеж в какой-то набор переменных, используйте 
	// structured bindings или функцию tie.

	return 0;
}