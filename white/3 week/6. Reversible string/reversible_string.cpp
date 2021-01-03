#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class ReversibleString {
	private:
		string data;

	public:
		// Реализуйте класс ReversibleString, хранящий строку и поддерживающий методы Reverse для переворота строки и ToString для получения строки.
		ReversibleString(const string& _data = "") : data(_data) {}

		void Reverse() {
			reverse(data.begin(), data.end());
		}

		string ToString() const {
			return data;
		}
};

int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	return 0;
}