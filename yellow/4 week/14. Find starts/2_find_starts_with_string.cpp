#include <bits/stdc++.h>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, string prefix) {
    // Все строки, начинающиеся с prefix, больше или равны строке "<prefix>"
    auto left = lower_bound(range_begin, range_end, prefix);

    string upper_bound = prefix;
    ++upper_bound[upper_bound.size() - 1];

    auto right = lower_bound(range_begin, range_end, upper_bound);

    return {left, right};
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix) {
    return equal_range(range_begin, range_end, prefix, [&](const string& a, const string& b) {
        // int compare( size_type pos1, size_type count1, const basic_string& str ) const;
        // str —   строка, с которой будет проведено сравнение
        // count1  —   количество символов данной строки для сравнения
        // pos1    —   позиция первого символа в данной строке, с которого начнется сравнение
        return a.compare(0, prefix.size(), b.substr(0, prefix.size())) < 0;
    });
}

int main() {
    const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

    const auto mo_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");    // moscow motovilikha
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    } cout << endl;

    const auto mt_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");    // 2 2
    cout << (mt_result.first - begin(sorted_strings)) << " " << (mt_result.second - begin(sorted_strings)) << endl;

    const auto na_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");    // 3 3
    cout << (na_result.first - begin(sorted_strings)) << " " << (na_result.second - begin(sorted_strings)) << endl;

    return 0;
}