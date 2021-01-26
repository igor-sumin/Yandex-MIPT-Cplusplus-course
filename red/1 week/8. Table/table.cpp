#include "../test_runner.h"
#include <vector>
#include <utility>

using namespace std;

// Реализуйте здесь шаблонный класс Table
template <typename T>
class Table {
private:
    vector<vector<T>> table;
public:
    Table(const size_t& row, const size_t& col) {
        this->Resize(row, col);
    }

    const vector<T>& operator[](size_t idx) const {
        return table[idx];
    }    

    vector<T>& operator[](size_t idx) {
        return table[idx];
    }

    void Resize(const size_t& idx, const size_t& jdx) {
        // table.resize(idx, vector<T>(jdx));
        table.resize(idx);
        for (auto& t : table) {
            t.resize(jdx);
        }
    }

    pair<size_t, size_t> Size() const {
        if (table.size() == 0 || table[0].size() == 0) 
            return make_pair(0, 0);

        return make_pair(table.size(), table[0].size());
    }
};

void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}
