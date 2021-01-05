#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";

    bool first = true;
    for(const auto& s : v) {
        if(!first) {
            os << ", ";
        } first = false;

        os << s;
    }

    return os << "}";
}

template <class T>
ostream& operator<<(ostream& os, const set<T>& v) {
    os << "{";

    bool first = true;
    for(const auto& s : v) {
        if(!first) {
            os << ", ";
        } first = false;

        os << s;
    }

    return os << "}";
}

template <class K, class V>
ostream& operator<<(ostream& os, const map<K, V>& m) {
    os << "{";

    bool first = true;
    for(const auto& kv : m) {
        if(!first) {
            os << ", ";
        } first = false;

        os << kv.first << ": " << kv.second;
    }

    return os << "}";
}

template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if(t != u) {
        ostringstream os;
        
        os << "Assertion failed: " << t << " != " << u;
        if(!hint.empty()) {
            cout << " hint: " << hint;
        }

        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
private:
    int fail_count = 0;
    
public:
    // TestRunner() : fail_count(0) {}

    // Принимает тестовые функции и ловит исключения
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            // Выводим сообщения в стандартный поток ошибок
            cerr << test_name << " OK" << endl;
        } catch(runtime_error& e) {
            fail_count++;
            cerr << test_name << "fail: " << e.what() << endl;
        } catch(...) {
            fail_count++;
            cerr << "Unknown exception caught" << endl;
        }
    }

    // GetFailCount() const {
    //     return fail_count;
    // }

    // Деструктор
    ~TestRunner() {
        if(fail_count > 0) {
            cerr << fail_count << " tests failed. Terminate";
            // Завершаем программу с ненулевым кодом возврата
            exit(1);
        }
    }
};

class Rational {
// Вы можете вставлять сюда различные реализации,
// чтобы проверить, что ваши тесты пропускают корректный код
// и ловят некорректный
private:
    int p, q;

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
    
    Rational(int np, int nq) {
        const int gcd = GCD(np, nq);
        p = np / gcd;
        q = nq / gcd;

        if (q < 0) {
            q = -q;
            p = -p;
        }
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }
};

void Test() {
    {
        Rational r(3, 10);

        AssertEqual(r.Numerator(), 3, "1");
        AssertEqual(r.Denominator(), 10, "2");
    }

    {
        Rational r(8, 12);

        AssertEqual(r.Numerator(), 2, "3");
        AssertEqual(r.Denominator(), 3, "4");
    }

    {
        Rational r(-4, 6);

        AssertEqual(r.Numerator(), -2, "5");
        AssertEqual(r.Denominator(), 3, "6");
    }

    {
        Rational r(4, -6);

        AssertEqual(r.Numerator(), -2, "7");
        AssertEqual(r.Denominator(), 3, "8");
    }

    {
        Rational r(0, 25);

        AssertEqual(r.Numerator(), 0, "9");
        AssertEqual(r.Denominator(), 1, "10");
    }

    {
        Rational dC;

        AssertEqual(dC.Numerator(), 0, "11");
        AssertEqual(dC.Denominator(), 1, "12");   
    }

    {
        Rational r(2147483647, 2147483647);

        AssertEqual(r.Numerator(), 1, "13");
        AssertEqual(r.Denominator(), 1, "14");
    }
}

int main() {
    TestRunner runner;
    // добавьте сюда свои тесты
    runner.RunTest(Test, "Test");

    return 0;
}
