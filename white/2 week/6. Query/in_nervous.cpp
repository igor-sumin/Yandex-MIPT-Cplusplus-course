#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include <iostream>

// 1 способ
int main() {
	int n;
	std::cin >> n;
	
	// n успокоившихся людей в очереди
	vector<bool> people(0, false);

	for(int i = 0; i < n; i++) {
		std::string s;
		cin >> s;

		if(s == "WORRY_COUNT") {
			int res = 0;
			for(auto c : people) {
				if(c == true) {
					res++;
				}
			}
			std::cout << res << std::endl;

		} else {
			int num;
			std::cin >> num;
			
			if(s == "WORRY" && num >= 0) {
				people[num] = true;
			} else if(s == "QUIET" && num >= 0) {
				people[num] = false;
			} else if(s == "COME") {
				if(num >= 0) {
					for(int i = 0; i < num; i++) {
						people.push_back(false);
					}	
				} else {
					for(int i = 0; i < -num; i++) {
						people.pop_back();
					}
				}
			} 
		}

		for(auto c : people) {
			std::cout << c << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}

// 2 способ
int main() {
	int q;
	std::cin >> q;
	std::vector<bool> is_nervous;

	for (int i = 0; i < q; ++i) {
			sdt::string operation_code;
			std::cin >> operation_code;

	    if (operation_code == "WORRY_COUNT") {
			// подсчитываем количество элементов в векторе is_nervous, равных true
			std::cout << count(begin(is_nervous), end(is_nervous), true) << endl;
	      
	    } else {
			if (operation_code == "WORRY" || operation_code == "QUIET") {
	        
				int person_index;
				std::cin >> person_index;

				// выражение в скобках имеет тип bool и равно true для запроса WORRY,
				// поэтому is_nervous[person_index] станет равным false или true
				// в зависимости от operation_code
				is_nervous[person_index] = (operation_code == "WORRY");
	        
	    	} else if (operation_code == "COME") {
	        
			    int person_count;
			    std::cin >> person_count;
			    
			    // метод resize может как уменьшать размер вектора, так и увеличивать,
			    // поэтому специально рассматривать случаи с положительным
			    // и отрицательным person_count не нужно
			    is_nervous.resize(is_nervous.size() + person_count, false);
	        
	      	}
	    }
	}

	return 0;
}