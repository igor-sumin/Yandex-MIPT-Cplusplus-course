#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>

// Не стоит в h файлы класть области видимости using namespace
using namespace std;

// Обьявление функции (function declaration)
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v);
template <class T>
ostream& operator<<(ostream& os, const set<T>& v);
template <class K, class V>
ostream& operator<<(ostream& os, const map<K, V>& m);

template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {});
void Assert(bool b, const string& hint);

class TestRunner {
private:
    int fail_count;
    
public:
    TestRunner();
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name);
    int GetFailCount() const;
    ~TestRunner();
};

// Определение шаблонных функций (function definiton)
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
void AssertEqual(const T& t, const U& u, const string& hint) {
    if(t != u) {
        ostringstream os;
        
        os << "Assertion failed: " << t << " != " << u;
        if(!hint.empty()) {
            cout << " hint: " << hint;
        }

        throw runtime_error(os.str());
    }
}

// Принимает тестовые функции и ловит исключения
template <class TestFunc>
void TestRunner::RunTest(TestFunc func, const string& test_name) {
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
