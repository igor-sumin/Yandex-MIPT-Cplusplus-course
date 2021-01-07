#include <bits/stdc++.h>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
    // Все строки, начинающиеся с '<prefix>', больше или равны строке "<prefix>"
    // string(1, prefix) == string(size_t n, char c);
    auto left = lower_bound(range_begin, range_end, string(1, prefix));

    // Перешли к следующему символу в таблице ASCII
    char next_prefix = static_cast<char>(prefix + 1);

    auto right = lower_bound(range_begin, range_end, string(1, next_prefix));

    return {left, right};
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
    // Преобразовали символ в строку
    string s = {prefix};
    // Перешли к следующему символу в таблице ASCII
    char next = prefix + 1;
    string s2 = {next};

    auto left = lower_bound(range_begin, range_end, s);
    auto right = upper_bound(range_begin, range_end, s2);

    return make_pair(left, right);
}

int main() {
    const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');  // moscow murmansk
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    } cout << endl;

    const auto p_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " << (p_result.second - begin(sorted_strings)) << endl;   // 2 2

    const auto z_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " << (z_result.second - begin(sorted_strings)) << endl;   // 3 3

    return 0;
}