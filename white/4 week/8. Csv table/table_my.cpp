#include <iostream>
#include <fstream>
#include <iomanip>

#include <vector>
#include <string>

using namespace std;

// 1 способ - мой
int main() {
	ifstream input("input.txt");
	vector<int> dates;
	int N, M;

	if(input) {
		input >> N;
		input >> M;

		int data;
		while(input >> data) {
			dates.push_back(data);
			input.ignore(1);
		}

		// счетчик столбцов
		int sch_N = 0;
		// счетчик строк
		int sch_M = M;
		for(int i = 0; i < dates.size(); i++) {
			if(i == sch_M - 1) {
				cout << setw(10) << dates[i];
				sch_M += M; 
				sch_N++;
				if(sch_N != N) {
					cout << endl;
				}
			} else {
				cout << setw(10) << dates[i] << " ";
			}
		}
	} else {
		cout << "error" << endl;
	}

	return 0;
}