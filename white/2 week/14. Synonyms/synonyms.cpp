#include <string>
#include <set>
#include <map>
#include <iostream>

using namespace std;

void PrintMap(const map<string, set<string>>& syn_for_word) {
    cout << "syn = " << endl;
    for(const auto& s : syn_for_word) {
        cout << s.first << ": ";
        for(const auto& i : s.second) {
            cout << i << " ";
        } cout << endl;
    }
}

int main() {
	int Q;
	cin >> Q;

    // Ответ на вопрос: как сдать прогу
    // Удобно для каждого слова уметь быстро получать набор его синонимов — тут помогут словари.
    // А чтобы по набору синонимов конкретного слова быстро проверять, есть ли там нужное слово, логично использовать множества.

    // Для каждого слова будем хранить множество его синонимов
    // map<конкретное слово, набор синонимов для конкретного слова>
    map<string, set<string>> syn_for_word;

    for(int i = 0; i < Q; i++) {
        string request;
        cin >> request;

        if(request == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;

            syn_for_word[word1].insert(word2);
            syn_for_word[word2].insert(word1);

            // PrintMap(syn_for_word);
        } else if(request == "COUNT") {
            string word;
            cin >> word;

            cout << syn_for_word[word].size() << endl;
        } else if(request == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;

            if(syn_for_word[word1].count(word2) == 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}