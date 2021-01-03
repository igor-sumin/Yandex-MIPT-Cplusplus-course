
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

    // //-> 1 способ
    // bool operator==(const Rational& op2) const {
    //     return ((this->Numerator() == op2.p) && (this->Denominator() == op2.q));
    // }

    //-> 2 способ
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

};

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = (r1 == r2);

        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = (c == Rational(2, 1));
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = (c == Rational(31, 63));
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
