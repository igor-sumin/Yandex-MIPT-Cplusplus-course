#include <iostream>
#include <string>
#include <vector>

bool isPalindrom(const std::string& s) {
	int sz = s.size();
	for (int i = 0; i < sz / 2; i++) {
		if (s[i] != s[sz - i - 1]) {
			return false;
		}
	}

	return true;
}

int main() {
	std::string a;
	while (std::cin >> a) {
		// std::boolalpha - превращает 1 в true, 0 в false
		std::cout << std::boolalpha << isPalindrom(a) << std::endl;
	}

	return 0;
}