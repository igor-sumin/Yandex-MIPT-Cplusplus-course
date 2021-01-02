#include <string>
#include <vector>
#include <map>
#include <set>

#include <algorithm>
#include <iostream>

using namespace std;

int CountUniqueWords(const vector<string>& words) {
	set<string> res(words.begin(), words.end());

	return res.size();
}

int main() {
	int n;
	cin >> n;

	//-> 1 способ
	vector<string> words(n);
	for(string& word : words) {
		cin >> word;
	}

	int res = CountUniqueWords(words);
	cout << res << endl;

	// //-> 2 способ
	// set<string> strings;
	// for (int i = 0; i < n; i++) {
	// 	string s;
	// 	cin >> s;
	// 	strings.insert(s);
	// }
	// cout << strings.size() << endl;

	return 0;
}