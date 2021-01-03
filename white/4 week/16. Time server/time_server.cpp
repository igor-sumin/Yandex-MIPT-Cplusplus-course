#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <exception>
using namespace std;

int i = 0;

void EnsureNextSymbolAndSkip(stringstream& stream) {
    if(stream.peek() != ':') {
        throw system_error(error_code());
    }
    stream.ignore(1);
}

string AskTimeServer() {
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */

    stringstream ss1("01:20:20");
    int hour, min, sec;
    char brack;

    ss1 >> hour;
    EnsureNextSymbolAndSkip(ss1);
    ss1 >> min;
    EnsureNextSymbolAndSkip(ss1);
    ss1 >> sec;

    if(min > 59 || sec > 59) {
        throw exception();
    }
    
    return(ss1.str());
}

class TimeServer {
private:
    string last_fetched_time;

public:
    TimeServer(string lft = "00:00:00") : last_fetched_time(lft) {}

    /* Реализуйте этот метод:
        * если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
        * если AskTimeServer() бросила исключение system_error, верните текущее значение
        поля last_fetched_time
        * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
    */
    string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer();
        } catch(const system_error& e) {
            ;
        } catch(...) {
            throw system_error();
        }

        return GetLastFetchedTime();
    }

    string GetLastFetchedTime() const {
        return last_fetched_time;
    }
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
