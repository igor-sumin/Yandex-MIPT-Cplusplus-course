#include <string>
#include <set>
#include <map>
#include <cassert>
#include <iostream>

// Что делать, если идеи тестов закончились?
// 1. Стоит выполнить декомпозицию программы и покрыть каждую часть юнит-тестами
// 2. Юнит-тесты придумать проще
// 3. Юнит-тесты - эффективный способ определить, в какой части программы ошибка точно есть

using namespace std;

enum class Status {
	ADD,
	COUNT,
	CHECK
};

// Даем псевдоним словарю
using Synonyms = map<string, set<string>>;

// Произедём декомпозицию программы
// То есть отделим логику работы со словарем от операций ввода и вывода
void AddSynonyms(Synonyms& syn, const string& word1, const string& word2) {
    syn[word2].insert(word1);
    syn[word1].insert(word1);
}

size_t GetSynonymsCount(Synonyms& syn, const string& word) {
    return syn[word].size();
}

bool CheckSynonyms(Synonyms& syn, const string& word1, const string& word2) {
    return syn[word1].count(word2) == 1;
}

// Напишем набор юнит-тестов
// Покроем выделенные функции тестами
void TestAdd() {
    {
        // Переменные вне скобок будут недоступными
        Synonyms empty;
        AddSynonyms(empty, "a", "b");

        // Предполагаем, что в словаре будут следующие записи
        const Synonyms expected = {
            {"a", {"b"}},
            {"b", {"a"}}
        };

        assert(empty == expected);
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

        assert(synonyms == expected);
    }

    cout << "TestAdd OK" << endl;
}

void TestCount() {
    {
        Synonyms empty;
        assert(GetSynonymsCount(empty, "a") == 0);
    }

    {
        Synonyms synonyms = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };

        assert(GetSynonymsCount(synonyms, "a") == 2);
        assert(GetSynonymsCount(synonyms, "b") == 1);
        assert(GetSynonymsCount(synonyms, "z") == 0);
    }

    cout << "TestCount OK" << endl;
}

void TestCheck() {
    {
        Synonyms empty;
        assert(!CheckSynonyms(empty, "a", "b"));
        assert(!CheckSynonyms(empty, "b", "a"));
    }

    {
        Synonyms synonyms = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };

        assert(CheckSynonyms(synonyms, "a", "b"));
        assert(CheckSynonyms(synonyms, "b", "a"));
        assert(CheckSynonyms(synonyms, "a", "c"));
        assert(CheckSynonyms(synonyms, "c", "a"));
        assert(!CheckSynonyms(synonyms, "b", "c"));
        assert(!CheckSynonyms(synonyms, "c", "b"));
    }

    cout << "TestCheck OK" << endl;
}

void TestAll() {
    TestCount();
    TestAdd();
    TestCheck();
}

int main() {
    TestAll();

    // После вызова получаем следующее:
    // TestCount OK
    // Assertion failed: empty == expected, file decomp_synonyms.cpp, line 43

    return 0;
}

int old_main() {
	int Q;
	cin >> Q;

    // Ответ на вопрос: как сдать прогу
    // Удобно для каждого слова уметь быстро получать набор его синонимов — тут помогут словари.
    // А чтобы по набору синонимов конкретного слова быстро проверять, есть ли там нужное слово, логично использовать множества.

    // Для каждого слова будем хранить множество его синонимов
    // map<конкретное слово, набор синонимов для конкретного слова>
    Synonyms syn_for_word;

    for(int i = 0; i < Q; i++) {
        string request;
        cin >> request;

        auto requestType = [](const string& request) {
        	if (request == "ADD")
        		return Status::ADD;
        	else if (request == "COUNT")
        		return Status::COUNT;
        	else 
        		return Status::CHECK;
        };

        switch(requestType(request)) {
        	case Status::ADD: {
				string word1, word2;
    	        cin >> word1 >> word2;

    	        AddSynonyms(syn_for_word, word1, word2);
    	        break;
        	}

        	case Status::CHECK: {
	            string word1, word2;
	            cin >> word1 >> word2;

	            if(CheckSynonyms(syn_for_word, word1, word2)) {
	                cout << "YES" << endl;
	            } else {
	                cout << "NO" << endl;
	            }
	            break;
        	}

        	case Status::COUNT: {
	            string word;
	            cin >> word;

	            cout << GetSynonymsCount(syn_for_word, word) << endl;
	            break;
        	}
	        
	        default:
	        	assert(false);
        }
    }

    return 0;
}