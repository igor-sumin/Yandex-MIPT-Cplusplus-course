#include <iostream>
#include <map>
#include <ostream>
#include <random>
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

bool IsPalindrom(const string& str) {
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
    for(int i = 0; i < str.size() / 2; i++) {
        if(str[i] != str[str.size() - i - 1]) {
            return false;
        }
    }

    return true;
}

void Test() {
    Assert(IsPalindrom(""), "is empty");
    Assert(IsPalindrom("a"), "single letter");
    Assert(IsPalindrom("a a"), "single space");
    Assert(IsPalindrom("abba"), "");
    Assert(IsPalindrom("ababa"), "");
    Assert(IsPalindrom("aba aba"), "");

    Assert(!IsPalindrom("ab"), "ab");
    Assert(!IsPalindrom("a b"), "single space.v2");
    Assert(!IsPalindrom("ab aba"), "ab aba");
    Assert(!IsPalindrom("aba ab"), "aba ab");
    Assert(!IsPalindrom("ba aba"), "ba aba");
    Assert(!IsPalindrom("ABBA   "), "`ABBA   ` is not a palindrome");
    Assert(!IsPalindrom("  ABBA"), "`  ABBA` is not a palindrome");
}

int main() {
    TestRunner runner;
    
    // добавьте сюда свои тесты
    runner.RunTest(Test, "Test");

    return 0;
}
