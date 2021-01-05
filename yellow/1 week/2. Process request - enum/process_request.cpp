#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <iostream>
using namespace std;

// Перечислимые типы основаны на целочисленных типах и благодаря этому эффективны.
enum class RequestType {
	ADD,
	REMOVE,
	NEGATE
};


// В отличие от if, оператор switch не позволяет проверять произвольные логические выражения. 
// Он позволяет сравнить заданную переменную (или результат выражения) 
// с различными конкретными значениями и выполнить различные действия в зависимости от того, 
// с каким значением произошло совпадение.
void ProcessRequest(set<int>& numbers, RequestType request_type, int request_data) {
	switch (request_type) {
		case RequestType::ADD:
			numbers.insert(request_data);
			break;
		case RequestType::REMOVE:
			numbers.erase(request_data);
			break;

		// Важная особенность оператора switch заключается в том, 
		// что при необходимости объявить переменную в одной из его веток всю ветку придётся заключить в блок из фигурных скобок:
		case RequestType::NEGATE: {  // фигурные скобки обязательны
		    bool contains = numbers.count(request_data) == 1;
		    if (contains) {
		      	numbers.erase(request_data);
		      	numbers.insert(-request_data);
		    }
		    break;
		}

		// Аналог else для оператора switch — ветка default. 
		// Предположим, например, что мы хотим перестраховаться от случаев добавления новых типов запросов 
		// и добавить вывод предупреждающего сообщения для неизвестного запроса:
		default:
    		cout << "Unknown request" << endl;
	}
}

int main() {
	ProcessRequest(numbers, RequestType::ADD, 8);
	ProcessRequest(numbers, RequestType::NEGATE, 8);
	ProcessRequest(numbers, RequestType::REMOVE, -8);

	// Выведет 0
	cout << static_cast<int>(RequestType::ADD) << endl;

	int request_code;
	cin >> request_code;
	auto request_type = static_cast<RequestType>(request_code);
	// Если ввести request_code = 7,
	// в переменной request_type окажется RequestType::NEGATE

	
	return 0;
}