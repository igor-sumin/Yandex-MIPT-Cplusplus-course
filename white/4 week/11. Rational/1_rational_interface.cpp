#include <iostream>
using namespace std;

class Rational {
private:
    // числитель
    int p;
    // знаменатель
    int q;

    // Нахождение НОД
    int GCD(int a, int b) {
        if(a < 0) {
            a = -a;
        }

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

    Rational(int zn, int chisl) : p(zn), q(chisl) {
        int del = GCD(p, q);

        p /= del;
        q /= del;

        if((p < 0 && q < 0) || (q < 0)) {
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

};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
