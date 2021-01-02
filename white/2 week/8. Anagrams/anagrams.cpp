#include <map>
#include <string>

#include <iostream>
using namespace std;

string BuildCharCounters(const string& word1, const string& word2) {
    map<char, int> w1;
    map<char, int> w2;

    for(const auto& s : word1) {
        w1[s]++;
    }

    for(const auto& s : word2) {
        w2[s]++;
    }

    return (w1 == w2) ? "YES\n" : "NO\n";
}

int main() {
    int Q;
    cin >> Q;
 
    for(int i = 0; i < Q; i++) {
        string word1, word2;
        cin >> word1 >> word2;

        string res = BuildCharCounters(word1, word2);
        cout << res;
    }

    return 0;
}