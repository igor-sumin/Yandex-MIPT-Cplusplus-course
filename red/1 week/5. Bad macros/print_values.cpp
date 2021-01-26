#include "../test_runner.h"

#include <sstream>
using namespace std;

#define PRINT_VALUES(out, x, y) out << (x) << endl << (y) << endl
	
// if {

// } true; else {

// } true;

// if 
// 	...
// else
// 	...

int main() {
	TestRunner tr;
	tr.RunTest([] {
		ostringstream output;
		PRINT_VALUES(output, 5, "red belt");
		ASSERT_EQUAL(output.str(), "5\nred belt\n");
	}, "PRINT_VALUES usage example 1");

	tr.RunTest([] {
		ostringstream os;
		if (false) 
			PRINT_VALUES(os, 1, 3);
		else
			PRINT_VALUES(os, 2, 3);

	}, "PRINT_VALUES usage example 2");

	tr.RunTest([] {
		int a = 2, b = 3;
    	if(false) PRINT_VALUES(cout, a, b);
	}, "PRINT_VALUES usage example 3");

	return 0;
}
