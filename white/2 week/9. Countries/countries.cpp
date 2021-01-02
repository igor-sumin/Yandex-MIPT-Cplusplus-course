#include <string>
#include <vector>
#include <map>

#include <algorithm>
#include <cmath>

#include <iostream>
using namespace std;

int cur = 0;

int main() {
	int Q;
	cin >> Q;

	map<string, string> wl;

	for(int i = 0; i < Q; i++) {
		string request;
		cin >> request;

		if(request == "CHANGE_CAPITAL") {
			string country, new_capital;
			cin >> country >> new_capital;

			if(wl.count(country) == 0) {
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
			} else {
				string old_capital = wl[country];
				if(old_capital == new_capital) {
					cout << "Country " << country << " hasn't changed its capital" << endl;
				} else {
					cout << "Country " << country << " has changed its capital from " << old_capital << " to " <<  new_capital << endl;
				}
			}

			wl[country] = new_capital;
		} else if(request == "RENAME") {
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;

			if((old_country_name == new_country_name) || (wl.count(old_country_name) == 0) || (wl.count(new_country_name) == 1)) {
				cout << "Incorrect rename, skip" << endl;
			} else {
				cout << "Country " << old_country_name << " with capital " << wl[old_country_name] << " has been renamed to " << new_country_name << endl;
				wl[new_country_name] = wl[old_country_name];
				wl.erase(old_country_name);
			}
		} else if(request == "ABOUT") {
			string country;
			cin >> country;

			if(wl.count(country) == 0) {
				cout << "Country " << country << " doesn't exist" << endl;
			} else {
				cout << "Country " << country << " has capital " << wl[country] << endl;
			}

		} else if(request == "DUMP") {
			if(wl.empty()) {
				cout << "There are no countries in the world" << endl;
			} else {
				for(const auto& s : wl) {
					cout << s.first << "/" << s.second << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}