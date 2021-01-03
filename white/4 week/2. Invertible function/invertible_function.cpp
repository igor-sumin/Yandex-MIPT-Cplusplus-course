#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <iostream>
using namespace std;

struct Image {
	double quality;
	double freshness;
	double rating;
};

struct Params {
	double a;	
	double b;
	double c;
};

class FunctionPart {
private:
	char operation;
	double value;
public:
	FunctionPart(char op, double _value) : operation(op), value(_value) {}

	double Apply(double source_value) const {
		if(operation == '+') {
			return source_value + value;
		} else if(operation == '-') {
			return source_value - value;
		}
	}

	void Invert() {
		if(operation == '-') {
			operation = '+';
		} else if(operation == '+') {
			operation = '-';
		}
	}
};

class Function {
private:
	vector<FunctionPart> parts;

public:
	double AddPart(char op, double value) {
		parts.push_back({op, value});
	}

	double Apply(double value) const {
		for(const FunctionPart& part : parts) {
			value = part.Apply(value);
		}

		return value;
	}

	void Invert() {
		for(FunctionPart& part : parts) {
			part.Invert();
		}

		reverse(parts.begin(), parts.end())
	}
};

Function MakeWeightFunction(const Params& params, const Image& image) {
	Function function;
	function.AddPart('-', image.freshness * params.a + params.b);
	function.AddPart('+', image.rating * params.c);
	return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
	Function function = MakeWeightFunction(params, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params, const Image& image, double weight) {
	Function function = MakeWeightFunction(params, image);
	function.Invert();
	return function.Apply(weight);
}

int main() {
	Image image = {10, 2, 6};
	Params params = {4, 2, 6};

	// 10 + (6 * 6) - (2 * 4 + 2) = ?
	cout << ComputeImageWeight(params, image) << endl;
	// 46 - 6 * 6 + 2 * 4 + 2 = ?
	cout << ComputeQualityByWeight(params, image, 46) << endl;

	return 0;
}