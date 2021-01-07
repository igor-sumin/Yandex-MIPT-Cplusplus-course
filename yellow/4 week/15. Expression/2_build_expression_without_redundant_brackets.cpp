#include <bits/stdc++.h>

using namespace std;

int main() {
	stringstream ss;
	stringstream prev;

	int x, n;
	cin >> x >> n;

	if(n == 0) {
		cout << x << endl;
		return 0;
	}

	ss << to_string(x);

	stack<char> st;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		int num; char sym;
		cin >> sym >> num;

		if(sym == '+' || sym == '-') {
			ss << " " << sym << " ";
		} else if(sym == '*' || sym == '/') {
			if(i != 0 && (st.top() == '+' || st.top() == '-')) {
				cnt++;
				ss << ")";
			}
			ss << " " << sym << " ";
		}
		st.push(sym);
		ss << num;
	}

	for(int i = 0; i < cnt; i++) {
		prev << "(";
	}

	cout << prev.str() + ss.str();
	return 0;
}