#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <tuple>
#include <utility>

#include <iostream>
using namespace std;

enum class Lang {
	DE, FR, IT
};

struct Region {
	string std_name;
	string parent_std_name;
	map<Lang, string> names;
	int64_t population;
};

auto GetRank(const Region& region) {
 	return tie(region.std_name, region.parent_std_name, region.names, region.population);
}

bool operator<(const Region& lhs, const Region& rhs) {
	return GetRank(lhs) < GetRank(rhs);
}

// Определяет какое максимальное число вхождений одного и того же элемента она содержит.
// 1 способ
int FindMaxRepetitionCount(const vector<Region>& regions) {
	if(regions.empty()) {
		return 0;
	}

	// Для определения словаря требуется перегрузить operator<
	map<Region, int> res;

	for(auto s : regions) {
		res[s]++;
	}

	int res_max = 1;
	for(auto s : res) {
		if(s.second > res_max) {
			res_max = s.second;
		}
	}

	return res_max;
}

// 2 способ
int FindMaxRepetitionCount(const vector<Region>& regions) {
	int result = 0;
	map<Region, int> repetition_count;

	for (const Region& region : regions) {
		result = max(result, ++repetition_count[region]);
	}

	return result;
}


int main() {
	cout << FindMaxRepetitionCount({
	    {
	        "Moscow",
	        "Russia",
	        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	        89
	    }, {
	        "Russia",
	        "Eurasia",
	        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
	        89
	    }, {
	        "Moscow",
	        "Russia",
	        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	        89
	    }, {
	        "Moscow",
	        "Russia",
	        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	        89
	    }, {
	        "Russia",
	        "Eurasia",
	        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
	        89
	    },
	}) << endl;	// 3
  
	cout << FindMaxRepetitionCount({
		{
			"Moscow",
			"Russia",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			89
		}, {
			"Russia",
			"Eurasia",
			{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
			89
		}, {
		  	"Moscow",
		  	"Russia",
		  	{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
		  	89
		}, {
		  	"Moscow",
		  	"Toulouse",
		  	{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		  	89
		}, {
		  	"Moscow",
		  	"Russia",
		  	{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		  	31
		},
	}) << endl;	// 1
  
  return 0;
}
