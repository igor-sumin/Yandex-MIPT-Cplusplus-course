#include <string>
#include <vector>
#include <map>
#include <set>

#include <algorithm>
#include <iostream>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& words) {
	set<string> res;

	for(const auto& s : words) {
		res.insert(s.second);
	}

	return res;
}

int main() {
	set<string> values = BuildMapValuesSet({
	    {1, "odd"},
	    {2, "even"},
	    {3, "odd"},
	    {4, "even"},
	    {5, "odd"}
	});

	for (const string& value : values) {
	  cout << value << " ";		// even odd
	}

	return 0;
}