#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class SortedStrings {
	private:
		vector<string> sort_strings;

	public:
	void AddString(const string& s) {
		// добавить строку s в набор
		sort_strings.push_back(s);
	}

	vector<string> GetSortedStrings() {
		// получить набор из всех добавленных строк в отсортированном порядке
		sort(sort_strings.begin(), sort_strings.end());

		return sort_strings;
	}
};

void PrintSortedStrings(SortedStrings& strings) {
	for (const string& s : strings.GetSortedStrings()) {
		cout << s << " ";
	}
	cout << endl;
}

int main() {
	SortedStrings strings;
  
	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	return 0;
}