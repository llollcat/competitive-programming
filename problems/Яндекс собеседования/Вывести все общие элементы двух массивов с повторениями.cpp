/* Вывести все общие элементы двух массивов с повторениями
 Сортировать не обязательно.
 [1, 2, 3, 2, 0]
[5, 1, 2, 7, 3, 2]

[1, 2, 2, 3]*/


#include <bits/stdc++.h>

using namespace std;


vector<int> fn(vector<int> &array1, vector<int> &array2) {
    unordered_map<int, pair<int, int>> counter;


    for (auto &it: array1) {
        ++counter[it].first;
    }


    for (auto &it: array2) {
        ++counter[it].second;
    }


    vector<int> out;
    for (auto &it: counter) {

        for (int i = 0; i < min(it.second.first, it.second.second); ++i) {
            out.push_back(it.first);


        }
    }


    return out;
}


int main() {
    vector<int> a = {1, 2, 3, 2, 0};
    vector<int> b = {5, 1, 2, 7, 3, 2};
    auto t = fn(a, b);


    for (auto &it: t) {
        cout << it << ' ';
    }


    return 0;
} 
