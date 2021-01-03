#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
using namespace std;

class Rational {
private:
    int p;
    int q;

    // Нахождение НОД
    int GCD(int a, int b) {
        if(a == 0) {
            return b;
        }

        return GCD(b % a, a);
    }

    // Нахождение НОК
    int LCM(int a, int b) {
        return (a * b) / GCD(a, b);
    }

public:
    Rational() : p(0), q(1) {
    }

    Rational(int zn, int chisl) {
        if(chisl == 0) {
            throw invalid_argument("Invalid argument");
        }

        const int del = GCD(zn, chisl);

        p = zn / del;
        q = chisl / del;

        if(q < 0) {
            p = -p;
            q = -q;
        }
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

    Rational operator+(const Rational& op2) {
        return Rational(p * op2.q + op2.p * q, q * op2.q);
    }

    Rational operator-(const Rational& op2) {
        return Rational(p * op2.q - op2.p * q, q * op2.q);
    }

    Rational operator*(const Rational& op2) {
        return Rational(p * op2.p, q * op2.q);
    }

    Rational operator/(const Rational& op2) {
        if(q == 0 || op2.p == 0) {
            throw domain_error("Invalid syntax.");
        }
        return Rational(p * op2.q, q * op2.p);
    }

    friend ostream& operator<<(ostream& stream, const Rational& hs) {
        return stream << hs.p << "/" << hs.q;
    }

    friend istream& operator>>(istream& stream, Rational& rat) {
        int p, q;
        char sym;

        if (stream) {
            stream >> p >> sym >> q;
            if (stream && sym == '/') {
                rat = Rational(p, q);
            }
        }

        return stream;
    }
};

char EnsureNextSymbolAndSkip(stringstream& stream) {
	char res;
	if (stream) {
        stream >> res;
		if(res == '+' || res == '-' || res == '*' || res == '/') {
			return res;
		}
	}

	assert(false);
}

Rational ParseRat(const string& data) {
	stringstream stream(data);

	Rational rat1, rat2;
	char sym;

    if (stream) {
        stream >> rat1;
    	sym = EnsureNextSymbolAndSkip(stream);
        stream >> rat2;
    }

    switch(sym) {
		case '+':
			return rat1 + rat2;
		case '-':
			return rat1 - rat2;
		case '*':
			return rat1 * rat2;
		case '/':
			return rat1 / rat2;
        default:
            assert(false);
	}
}

int main() {
	// (!) Поскольку строка при вводе cin считывается до разделителя (пробела или переноса строки), то мы используем метод getline
	string data;
    getline(cin, data);

    try {
    	// Распарсим строку
    	Rational rat = ParseRat(data);
    	cout << rat.Numerator() << "/" << rat.Denominator() << endl;

    } catch (const exception& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}
