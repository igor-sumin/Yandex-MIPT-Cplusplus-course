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

std::vector<std::string> PalindromFilter(const std::vector<std::string>& pals, int min) {
	std::vector<std::string> res;
	for (const std::string& pal : pals)
		if (min <= pal.size() && isPalindrom(pal))
			res.push_back(pal);

	return res;
}

int main() {
	int min, n;
	std::cin >> min >> n;

	std::vector<std::string> pals(n);
	for (auto& pal : pals) {
		std::cin >> pal;
	}

	std::vector<std::string> res = PalindromFilter(pals, min);
	bool first = true;
	for (const std::string& r : res) {
		if (!first) {
			std::cout << ", ";
		} 

		first = false;
		std::cout << r;
	}

	return 0;
}