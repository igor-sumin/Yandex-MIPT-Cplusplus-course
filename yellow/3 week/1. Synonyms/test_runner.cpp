#include "test_runner.h"

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

TestRunner::TestRunner() : fail_count(0) {}

int TestRunner::GetFailCount() const {
    return fail_count;
}

// Деструктор
TestRunner::~TestRunner() {
    if(fail_count > 0) {
        cerr << fail_count << " tests failed. Terminate";
        // Завершаем программу с ненулевым кодом возврата
        exit(1);
    }
}