// #include "test_runner.h"
// #include "../test_runner.h"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template <class T>
class Deque {
private:
	// Для вставки в front
	vector<T> vFront;
	// Для вставки в back
	vector<T> vBack;

	T& AtImpl(size_t idx) {
		int n = vFront.size();
		if (idx < n) {
			return vFront[n - idx - 1];
		}

		return vBack[idx - n];
	}

	void CheckIndex(size_t idx) const {
	    if (idx >= Size()) {
	      	throw out_of_range("Index is out of range");
	    }
	}

public:
	Deque() = default;

	bool Empty() const {
		return vFront.empty() && vBack.empty();
	}

	size_t Size() const {
		return vFront.size() + vBack.size();
	}

	T& operator[](size_t idx) {
		return AtImpl(idx);
	}

	const T& operator[](size_t idx) const {
		return AtImpl(idx);
	}

	T& At(size_t idx) {
		CheckIndex(idx);
		return this->operator[](idx);
	}

	const T& At(size_t idx) const {
		CheckIndex(idx);
		return this->operator[](idx);
	}

	T& Front() {
		if (vFront.empty()) {
			return vBack.front();
		}
		return vFront.back();
	}

	const T& Front() const {
		if (vFront.empty()) {
			return vBack.front();
		}
		return vFront.back();
	}

	T& Back() {
		if (vBack.empty()) {
			return vFront.front();
		}
		return vBack.back();
	}

	const T& Back() const {
		if (vBack.empty()) {
			return vFront.front();
		}
		return vBack.back();
	}

	void PushFront(const T& elem) {
		vFront.push_back(elem);
	}

	void PushBack(const T& elem) {
		vBack.push_back(elem);
	}
};

int main() {

    return 0;
}