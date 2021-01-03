#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	ifstream input("input.txt");
	double line;

	if(input) {
		cout << fixed << setprecision(3);
		while(input >> line) {
			cout << line << endl;
		}
	} else {
		cout << "error" << endl;
	}

	return 0;
}