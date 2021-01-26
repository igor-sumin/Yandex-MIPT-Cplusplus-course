#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Оператор## предварительной обработки выполняет вставку токена. Когда макрос раскрывается, 
// два токена по обе стороны от каждого '##' объединяются в один токен, который затем заменяет '##' и два исходных токена в расширении макроса.
// // #define f(a, b) a##b

// Рассмотрим работу макросов в порядке их развёртывания:
// 1. макрос UNIQ_ID просто передаёт ___LINE__ как параметр макросу h;
#define UNIQ_ID h(__LINE__)
// 2. макрос h разворачивает ___LINE__ и передаёт его как параметр макросу f;
#define h_(line) f(line)
// 3. макрос f склеивает оператором## loc_var_ с номером строки.
#define f(line)	 loc_var_##line

int main() {
	int UNIQ_ID = 0;
	string UNIQ_ID = "hello";
	vector<string> UNIQ_ID = {"hello", "world"};
	vector<int> UNIQ_ID = {1, 2, 3, 4};

	return 0;
}