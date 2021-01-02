#include <string>
#include <vector>
#include <map>

#include <algorithm>

#include <iostream>
using namespace std;

int cur = 0;

int main() {
	int Q;
	cin >> Q;

	// Автобус №51 следует по 3 остановкам: ЗКПД-4 Гаугеля Университет_Лобачевского
	map<string, vector<string>> buses;
	vector<string> dop1;

	for(int i = 0; i < Q; i++) {
		string request;
		cin >> request;

		if(request == "NEW_BUS") {
			string bus;
			cin >> bus;

			int stop_count;
			cin >> stop_count;
			
			vector<string> w;
			for(int j = 0; j < stop_count; j++) {
				string stop_j;
				cin >> stop_j;

				// buses[bus].push_back(stop_j);
				w.push_back(stop_j);
			}

			buses[bus] = w;
			dop1.push_back(bus);

		} else if(request == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;

			vector<string> dop3;
			bool k = false;
			for(const auto& s : buses) {
				for(const auto& ost : s.second) {
					if(ost == stop) {
						dop3.push_back(s.first);
						k = true;
					}
				}
			}
			if(!k) {
				cout << "No stop" << endl;
			} else {
				// Для правильного вывода результата
				for(int i = 0; i < dop1.size(); i++) {
					for(int j = 0; j < dop3.size(); j++) {
						if(dop1[i] == dop3[j]) {
							cout << dop1[i] << " ";
						}
					}
				}
				dop3.clear();
				cout << endl;
			}

		} else if(request == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;

			vector<string> dop3;
			if(buses.count(bus) != 0) {
				for(const auto& stop : buses[bus]) {
					cout << "Stop " << stop << ": ";
					bool k = false;
					for(const auto& s : buses) {

						for(const auto& stop_i : s.second) {
							if(stop == stop_i) {
								if(s.first == bus) {
									continue;
								} else {
									dop3.push_back(s.first);
									k = true;
								}
							}
						}
					}
					if(!k) {
						cout << "no interchange" << endl;
					} else {
						// Для правильного вывода результата
						for(int i = 0; i < dop1.size(); i++) {
							for(int j = 0; j < dop3.size(); j++) {
								if(dop1[i] == dop3[j]) {
									cout << dop1[i] << " ";
								}
							}
						}
						cout << endl;
						dop3.clear();
					}
				}
			} else {
				cout << "No bus" << endl;
			}

		} else if(request == "ALL_BUSES") {
			if(!buses.empty()) {
				for(const auto& s : buses) {
					cout << "Bus " << s.first << ": ";
					for(const auto& stop : s.second) {
						cout << stop << " ";
					}
					cout << endl;
				}
			} else {
				cout << "No buses" << endl;
			}			
		}
	}

	return 0;
}