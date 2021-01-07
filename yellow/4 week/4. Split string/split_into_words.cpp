#include <bits/stdc++.h>

using namespace std;

// Мое решение
vector<string> SplitIntoWords(const string& s) {
	// >> значит istringstream
	// << значит ostringstream
	istringstream ss(s);

	vector<string> res;
	string word;

	while(ss >> word) {
		res.push_back(word);
	}

	return res;
}

// Альтернативное решение
vector<string> SplitIntoWords1(const string& str) {
	vector<string> result;

	auto str_begin = begin(str);
	const auto str_end = end(str);

	while (true) {
		auto it = find(str_begin, str_end, ' ');
		// Полуинтервал [str_begin, it) — очередное слово
		result.push_back(string(str_begin, it));

		if (it == str_end) {
			// Если пробелов больше нет, цикл пора завершить.
			break;
		} else {
			// Иначе первый символ после пробела — начало очередного слова.
			str_begin = it + 1;
		}
	}

	return result;
}

int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);	// 4 С/Cpp/Java/Python
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;
  
	return 0;
}