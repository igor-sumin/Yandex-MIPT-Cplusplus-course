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
	map<int, string> business;
	vector<vector<int>> month(12);

	for(int i = 0; i < Q; i++) {
		string operation_code;
		cin >> operation_code;

		if(operation_code == "NEXT") {
			int old = cur;
			
			month[cur].resize(31);
			cur++;

			if(cur == 12) {
				cur = 0;
			}

			if(cur == 0 || cur == 2 || cur == 4 || cur == 6 || cur == 7 || cur == 9 || cur == 11) {
				month[cur].resize(31);
			} else if(cur == 1) {
				month[cur].resize(28);

				// Февраль.size() < Январь.size()
				if(month[cur].size() < month[old].size()) {
					if(!business[29].empty()) {
						if(business[28].empty()) {
							business[28] = business[29];
						} else {
							business[28] = business[28] + " " + business[29];
						}
						business[29].clear();
					}
					if(!business[30].empty()) {
						if(business[28].empty()) {
							business[28] = business[30];
						} else {
							business[28] = business[28] + " " + business[30];
						}
						business[30].clear();
					}
					if(!business[31].empty()) {
						if(business[28].empty()) {
							business[28] = business[31];
						} else {
							business[28] = business[28] + " " + business[31];
						}
						business[31].clear();
					}
				}
			} else {
				month[cur].resize(30);

				if(month[cur].size() < month[old].size()) {
					if(!business[31].empty()) {
						if(business[30].empty()) {
							business[30] = business[31];
						} else {
							business[30] = business[30] + " " + business[31];
						}
						business[31].clear();
					}
				}
			}
		} else {
			int day;
			cin >> day;

			if(operation_code == "ADD") {
				string empl;
				cin >> empl;

				if(!business[day].empty()) {
					business[day] = business[day] + " " + empl;
				} else {
					business[day] = empl;
				}
			
			} else if(operation_code == "DUMP") {
				if(!business[day].empty()) {
					cout << count(business[day].begin(), business[day].end(), ' ') + 1 << " ";
					cout << business[day] << endl;
				} else {
					cout << "0" << endl;
				}
			}
		}
	}

	return 0;
}

// // /--> Случаи для NEXT
// // 1 случай
// // Январь -> Февраль
// // 31 день -> 29 30 31 => 28 день -> 28  
// for(int i = 28; i < 31; i++) {
// 	значение_текущего_месяца[27].push_back(значение_предыдущего_месяца[i]);
// }

// // 2 случай
// // Март (31) -> Апрель(30)
// значение_текущего_месяца[29].push_back(значение_предыдущего_месяца[30]);

// // 3 случай
// // Апрель (30) -> Февраль(28)
// // 30 дней -> 29 30 => 28
// for(int i = 28; i < 30; i++) {
// 	значение_текущего_месяца[27].push_back(значение_предыдущего_месяца[i]);
// }