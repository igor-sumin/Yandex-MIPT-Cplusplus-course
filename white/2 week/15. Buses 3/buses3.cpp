#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
	int q;
	cin >> q;

	map<set<string>, int> buses;

	for(int i = 0; i < q; i++) {
		int n;
		cin >> n;

		set<string> stops;
		for(int j = 0; j < n; j++) {
			string stop;
			cin >> stop;

			stops.insert(stop);
		}

		if(!buses.count(stops)) {
			const int size = buses.size() + 1;
			buses[stops] = size;
			cout << "New bus " << size << endl;

		} else {
			cout << "Already exists for " << buses[stops] << endl;
		}
	}

	return 0;
}

