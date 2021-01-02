#include <string>
#include <vector>
#include <map>

#include <algorithm>

#include <iostream>
using namespace std;

int main() {
	int Q;
	cin >> Q;

	map<int, vector<string>> buses;
	for(int i = 0, k = 1; i < Q; i++, k++) {
		int N;
		cin >> N;

		vector<string> tmp;
		for(int j = 0; j < N; j++) {
			string stop_j;
			cin >> stop_j;

			tmp.push_back(stop_j);
			buses[k] = tmp;
		}

		bool f = false;
		for(int l = 1; l < k; l++) {
			if(buses[k] == buses[l]) {
				cout << "Already exists for " << l << endl;
				f = true; k--;
				break;
			}
		}
		if(!f) {
			cout << "New bus " << k << endl;
		}
	}

	return 0;
}