#include <string>
#include <set>
#include <map>

// Не стоит в h файлы класть области видимости using namespace
using namespace std;

using Synonyms = map<string, set<string>>;

// Обьявление функции (function declaration)
void AddSynonyms(Synonyms& syn, const string& word1, const string& word2);
size_t GetSynonymsCount(Synonyms& syn, const string& word);
bool CheckSynonyms(Synonyms& syn, const string& word1, const string& word2);