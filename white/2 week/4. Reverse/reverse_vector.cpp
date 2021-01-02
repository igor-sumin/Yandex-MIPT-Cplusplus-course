#include <iostream>
#include <vector>

std::vector<int> Reverse_copy(const std::vector<int>& input) {
    std::vector<int> result;
    for (int i = input.size() - 1; i >= 0; --i) {
        result.push_back(input[i]);
    }
    return result;
}

void Reverse_best(std::vector<int>& vec) {
	for (int i = 0; i < (int)vec.size() / 2; i++) {
		int temp = vec[i];
		vec[i] = vec[vec.size() - i - 1];
		vec[vec.size() - i - 1] = temp;
	}
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> numbers(n);
	for (auto& num : numbers)
		std::cin >> num;

	Reverse_best(numbers);
	for (auto& num : numbers)
		std::cout << num << " ";
	
	return 0;
}