#include "synonyms.h"

// Определение функции (function definiton)
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