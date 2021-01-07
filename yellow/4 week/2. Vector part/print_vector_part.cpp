#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart_worst(const vector<int>& numbers) {
	vector<int> res;

	for(auto it = numbers.begin(); it != numbers.end(); ++it) {
		if((*it) < 0) {
			break;
		}
		res.push_back(*it);
	}

	reverse(res.begin(), res.end());
	for(auto s : res) {
		cout << s << " ";
	}
}

void PrintVectorPart_best(const vector<int>& numbers) {
	auto negative_it = find_if(numbers.begin(), numbers.end(), [](int number) {
		return number < 0;
	});

	for (auto it = negative_it; it != numbers.begin(); ) {
		cout << *(--it) << " ";
	}
}

int main() {
	PrintVectorPart_best({6, 1, 8, -5, 4});	// 8 1 6
	cout << endl;
	PrintVectorPart_best({-6, 1, 8, -5, 4});  // ничего не выведется
	cout << endl;
	PrintVectorPart_best({6, 1, 8, 5, 4});	// 4 5 8 1 6
	cout << endl;

	return 0;
}