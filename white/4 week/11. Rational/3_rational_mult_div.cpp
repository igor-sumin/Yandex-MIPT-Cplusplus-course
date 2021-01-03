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
    Rational() : p(0), q(1) {
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

    bool operator==(const Rational& op2) {
        return ((p == op2.p) && (q == op2.q));
    }

    Rational operator+(const Rational& op2) {
        if(q == op2.q) {
            return Rational(p + op2.p, q);
        } else {
            int lcm = LCM(q, op2.q);

            int ql = lcm / q;
            int qr = lcm / op2.q;

            return Rational(p * ql + op2.p * qr, lcm);
        }
    }

    Rational operator-(const Rational& op2) {
        if(q == op2.q) {
            return Rational(p - op2.p, q);
        } else {
            int lcm = LCM(q, op2.q);

            int ql = lcm / q;
            int qr = lcm / op2.q;

            return Rational(p * ql - op2.p * qr, lcm);
        }
    }

    Rational operator*(const Rational& op2) {
        if(q == op2.p && p == op2.q) {
            return Rational(1, 1);
        } else {
            return Rational(p * op2.p, q * op2.q);
        }
    }

    Rational operator/(const Rational& op2) {
        if(p == op2.p && q == op2.q) {
            return Rational(1, 1);
        } else {
            return Rational(p * op2.q, q * op2.p);
        }
    }
};

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
