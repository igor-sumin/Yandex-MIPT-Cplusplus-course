#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <iostream>
using namespace std;

int main() {
	// Возможное значение массы равно 10^4 * 10^4 * 10^4 * 10^5 * 100 = 10^19, что умещается лишь в тип uint64_t.
	// m = r * w * h * d

	int n, r; 
	cin >> n >> r;

	uint64_t res = 0;
	for(int i = 0; i < n; i++) {
		uint64_t m = 1;

		vector<uint64_t> bl_size(3);
		for(auto& s : bl_size) {
			cin >> s;
			m *= s;
		}

		res += m;
	}
	
	res *= r;
	cout << res << endl;

	// 2 способ
	int N, R;
	cin >> N >> R;
	
	uint64_t answer = 0;
	for (int i = 0; i < N; ++i) {
		int W, H, D;
		cin >> W >> H >> D;
		// Если не привести W к типу uint64_t перед умножением, 
		// произведение будет иметь тип int и случится переполнение.
		// Альтернативное решение — хранить сами W, H, D в uint64_t
		answer += static_cast<uint64_t>(W) * H * D;
	}
	
	answer *= R;
	cout << answer << endl;
	
	return 0;
}