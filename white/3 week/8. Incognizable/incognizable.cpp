#include <iostream>
#include <vector>
#include <string>

using namespace std;
	
struct Incognizable {
	int x = 0;
	int y = 0;
};

void PrintStruct(const Incognizable& koord) {
	cout << koord.x << ", " << koord.y << endl;
}

int main() {
	Incognizable a;
	Incognizable b = {};
	Incognizable c = {0};
	PrintStruct(c);
	Incognizable d = {0, 1};
	PrintStruct(d);

	return 0;
}