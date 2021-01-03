#include <iostream>
#include <sstream>
#include <typeinfo>
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

    bool operator==(const Rational& op2) const {
        return ((Numerator() == op2.p) && (Denominator() == op2.q));
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
            // int pr = p * op2.q;
            // int qr = q * op2.p;

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

    friend ostream& operator<<(ostream& stream, const Rational& hs) {
        stream << hs.p << "/" << hs.q;

        return stream;
    }

    friend istream& operator>>(istream& stream, Rational& hs) {
        stream >> hs.p;
        stream.ignore(1);
        stream >> hs.q;

        int del = hs.GCD(hs.p, hs.q);

        hs.p /= del;
        hs.q /= del;

        return stream;
    }
};

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
