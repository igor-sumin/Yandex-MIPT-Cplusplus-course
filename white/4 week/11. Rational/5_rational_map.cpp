#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
private:
    // числитель
    int p;
    // знаменатель
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

    bool operator==(const Rational& op2) const {
        return (Numerator() == op2.p) && (Denominator() == op2.q);
    }

    Rational operator+(const Rational& op2) {
        return Rational(p * op2.q + op2.p * q, q * op2.q);
    }

    // вычитание реализуем аналогично сложению
    // дублирования кода можно было избежать, определив для класса Rational операцию унарного минуса: 
    // тогда разность lhs и rhs можно было бы вычислить как lhs + (-rhs)
    Rational operator-(const Rational& op2) {
        return Rational(p * op2.q - op2.p * q, q * op2.q);
    }

    Rational operator*(const Rational& op2) {
        return Rational(p * op2.p, q * op2.q);
    }

    Rational operator/(const Rational& op2) {
        return Rational(p * op2.q, q * op2.p);
    }

    friend istream& operator>>(istream& stream, Rational& hs) {
        int n, d;
        char c;

        if (stream) {
            stream >> n >> c >> d;
            if (stream && c == '/') {
                hs = Rational(n, d);
            }
        }

        return stream;
    }

    friend ostream& operator<<(ostream& stream, const Rational& hs) {
        return stream << hs.p << "/" << hs.q;
    }

    bool operator<(const Rational& op2) const {
        if(p == op2.p) {
            return (q > op2.q);
        }

        return (p * op2.q) < (op2.p * q);
    }
};

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}