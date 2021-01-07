#include <bits/stdc++.h>

using namespace std;

int main() {
	stringstream ss;
	int x;
	cin >> x;

	int n;
	cin >> n;

	if(n == 0) {
		cout << x << endl;
		return 0;
	}

	for(int i = 0; i < n; i++) {
		ss << "(";
	}

	ss << to_string(x) << ")";
	for(int i = 0; i < n; i++) {
		char sym;
		int num;

		cin >> sym >> num;

		ss << " " << sym << " " << to_string(num) << ")";
	}

	cout << ss.str();

	return 0;
}