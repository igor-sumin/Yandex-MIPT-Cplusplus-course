#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iomanip>
 
using namespace std;

// Реализация функций синонимов
#include "synonyms.h"
// Юнит-тесты
#include "tests.h"

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