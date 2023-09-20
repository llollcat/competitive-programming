#include <bits/stdc++.h>

using namespace std;

/*
пример бинарного поиска, который возвращает индекс элемента по его значению.
*/
int indexfElementByBinarySearch(const vector<int>& object, int element){
    int index;
    int left_bound = 0;
    int right_bound = static_cast<int>(object.size())-1;

    // пока левая граница не "перескочит" правую
    while (left_bound <= right_bound) {
        index = (left_bound + right_bound) / 2;

        // если мы нашли элемент,
        if (element == object[index])
            return index;

        if (element < object[index])
            right_bound = index - 1;

        else
            left_bound = index + 1;
    }
    
    return -1;
} 
