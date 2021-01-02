#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int num = 5;
	std::cin >> num;

	std::vector<int> res;
	while (num) {
		res.push_back(num & 1);
		num /= 2;
	}

	std::reverse(res.begin(),res.end());
	for (const int& r : res)
		std::cout << r;
	std::cout << std::endl;

	return 0;
}