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

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
    string name;  // изначально имя неизвестно

    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
    for (const auto& item : names) {
        // если очередной год не больше данного, обновляем имя
        if (item.first <= year) {
            name = item.second;
        } else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
        }
    }
  
    return name;
}

class Person {
private:
    map<int, string> first_names;
    map<int, string> last_names;
    
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }
    
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }
    
    string GetFullName(int year) {
        // получаем имя и фамилию по состоянию на год year
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);
    
        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
            
        // если неизвестно только имя
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";
      
        // если неизвестна только фамилия
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";
      
        // если известны и имя, и фамилия
        } else {
            return first_name + " " + last_name;
        }
    }
};

void TestPredefinedLastNameFirst() {
    Person person;

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeFirstName(1967, "Polina");

    AssertEqual(person.GetFullName(1964), "Incognito");
    AssertEqual(person.GetFullName(1966), "Sergeeva with unknown first name");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");
}

void TestPredefined() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");

    AssertEqual(person.GetFullName(1964), "Incognito");
    AssertEqual(person.GetFullName(1966), "Polina with unknown last name");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");

    person.ChangeFirstName(1969, "Appolinaria");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");
    AssertEqual(person.GetFullName(1969), "Appolinaria Sergeeva");
    AssertEqual(person.GetFullName(1970), "Appolinaria Sergeeva");

    person.ChangeLastName(1968, "Volkova");
    AssertEqual(person.GetFullName(1967), "Polina Sergeeva");
    AssertEqual(person.GetFullName(1968), "Polina Volkova");
    AssertEqual(person.GetFullName(1969), "Appolinaria Volkova");

}

int main() {
    TestRunner runner;
    runner.RunTest(TestPredefined, "TestPredefined");
    runner.RunTest(TestPredefinedLastNameFirst, "TestPredefinedLastNameFirst");
    return 0;
}
