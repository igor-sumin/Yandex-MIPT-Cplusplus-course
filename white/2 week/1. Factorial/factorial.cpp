#include <iostream>

int Factorial(int a) {
	if(a > 0) {
		int per = 1;
		
		for(int i = 2; i <= a; i++) {
			per *= i;
		}

		return per;

	} else {
		return 1;
	}
}

int main() {
	int a;
	std::cin >> a;

	int res = Factorial(a);
	std::cout << res;

	return 0;
}