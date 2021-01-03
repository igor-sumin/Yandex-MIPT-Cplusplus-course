#include <iostream>
#include <exception>
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
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int zn, int chisl) {
        if(chisl == 0) {
            throw invalid_argument("Invalid syntax.");
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

    Rational operator/(const Rational& op2) {
        if(q == 0 || op2.p == 0) {
            throw domain_error("Invalid syntax.");
        }
        return Rational(p * op2.q, q * op2.p);
    }
};

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (const invalid_argument& ia) {
        cout << ia.what() << endl;
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (const domain_error& de) {
        cout << de.what() << endl;
    }

    cout << "OK" << endl;
    return 0;
}
