#include <algorithm>
#include "sum_reverse_sort.h"

using namespace std;

int Sum(int x, int y) {
	return x + y;
}

string Reverse(string s) {
	int n = s.size();
	for(int i = 0; i < n / 2; i++) {
		char c = s[i];
		s[i] = s[n - 1 - i];
		s[n - 1 - i] = c;
	}

	return s;
	// return reverse(s.begin(), s.end());
}

void Sort(vector<int>& nums) {
	sort(nums.begin(), nums.end());
}

