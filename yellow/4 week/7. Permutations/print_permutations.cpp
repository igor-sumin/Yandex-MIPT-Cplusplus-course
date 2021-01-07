#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;
    assert(n <= 9);

    vector<int> s(n);
    // Заполняет диапазон последовательно возрастающими значениями
    iota(n.begin(), n.end(), 1);

    // Меняет порядок следования элементов в диапазоне на противоположный
    reverse(n.begin(), n.end());

    // Преобразует диапазон в предыдущую (лексикографически) перестановку,
    // если она существует, и возвращает true,
    // иначе (если не существует) - в последнюю (наибольшую) и возвращает false
    do {
        for(auto l : s) {
        	cout << l << " ";
        } cout << endl;
    } while(next_permutation(s.rbegin(), s.rend()));

	return 0;
}