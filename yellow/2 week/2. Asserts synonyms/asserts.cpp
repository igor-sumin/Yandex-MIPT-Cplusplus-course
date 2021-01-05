#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

using Synonyms = map<string, set<string>>;

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



void AddSynonyms(Synonyms& syn, const string& word1, const string& word2) {
    syn[word2].insert(word1);
    syn[word1].insert(word2);
}

size_t GetSynonymsCount(Synonyms& syn, const string& word) {
    return syn[word].size();
}

bool CheckSynonyms(Synonyms& syn, const string& word1, const string& word2) {
    return syn[word1].count(word2) == 1;
}



void TestAdd() {
    {
        Synonyms empty;
        AddSynonyms(empty, "a", "b");

        const Synonyms expected = {
            {"a", {"b"}},
            {"b", {"a"}}
        };

        AssertEqual(empty, expected, "Add to empty");
    }

    {
        Synonyms synonyms = {
            {"a", {"b"}},
            {"b", {"a", "c"}},
            {"c", {"b"}}
        };

        AddSynonyms(synonyms, "a", "c");
        const Synonyms expected = {
            {"a", {"b", "c"}},
            {"b", {"a", "c"}},
            {"c", {"a", "b"}}
        };

        AssertEqual(synonyms, expected, "Add to non-empty");
    }
}

void TestCount() {
    {
        Synonyms empty;
        // Поскольку AssertEqual позволяет сравнивать переменные различных типов,
        // то вызывается предупреждение, 
        // так как GetSynonymsCount возвращает size_t, а 0 - это int'ое значение. 
        // Поэтому мы приводим 0 к безнаковому типу 0u
        AssertEqual(GetSynonymsCount(empty, "a"), 0u, "count for empty");
    }

    {
        Synonyms synonyms = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };

        AssertEqual(GetSynonymsCount(synonyms, "a"), 2u, "count for a");
        AssertEqual(GetSynonymsCount(synonyms, "b"), 1u, "count for b");
        AssertEqual(GetSynonymsCount(synonyms, "z"), 0u, "count for z");
    }
}

void TestCheck() {
    {
        Synonyms empty;
        Assert(!CheckSynonyms(empty, "a", "b"), "empty a b");
        Assert(!CheckSynonyms(empty, "b", "a"), "empty b a");
    }

    {
        Synonyms synonyms = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };

        Assert(CheckSynonyms(synonyms, "a", "b"), "");
        Assert(CheckSynonyms(synonyms, "b", "a"), "");
        Assert(CheckSynonyms(synonyms, "a", "c"), "");
        Assert(CheckSynonyms(synonyms, "c", "a"), "");
        Assert(!CheckSynonyms(synonyms, "b", "c"), "");
        Assert(!CheckSynonyms(synonyms, "c", "b"), "");
    }
}



class TestRunner {
private:
    int fail_count;
    
public:
    TestRunner() : fail_count(0) {}

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

    GetFailCount() const {
        return fail_count;
    }

    // Деструктор
    ~TestRunner() {
        if(fail_count > 0) {
            cerr << fail_count << " tests failed. Terminate";
            // Завершаем программу с ненулевым кодом возврата
            exit(1);
        }
    }
};

void TestAll() {
    TestRunner rt;

    // Передаем в качестве параметра функцию. 
    // (!) Скобки писать нельзя. Только имя самой функции
    rt.RunTest(TestCheck, "TestCheck");
    rt.RunTest(TestCount, "TestCount");
    rt.RunTest(TestAdd, "TestAdd");
}



int main() {
    TestAll();

	int Q;
	cin >> Q;

    Synonyms syn_for_word;

    for(int i = 0; i < Q; i++) {
        string request;
        cin >> request;
        if(request == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;

            AddSynonyms(syn_for_word, word1, word2);
        } else if(request == "COUNT") {
            string word;
            cin >> word;

            cout << GetSynonymsCount(syn_for_word, word) << endl;
        } else if(request == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;

            if(CheckSynonyms(syn_for_word, word1, word2)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}