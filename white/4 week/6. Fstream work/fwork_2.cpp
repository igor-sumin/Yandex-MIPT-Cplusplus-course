#include <iostream>
#include <fstream>

#include <vector>
#include <string>

using namespace std;

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");

	if(input) {
		string line;
		while(getline(input, line)) {
			output << line << endl;
		}
	} else {
		cout << "error" << endl;
	}

	return 0;
}