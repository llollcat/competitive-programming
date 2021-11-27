#include <bits/stdc++.h>

using namespace std;


int indexOfElementByBinarySearch(const vector<int>& object, int element){
    int pointer;
    int left_bound = 0;
    int right_bound = static_cast<int>(object.size())-1;

    // пока левая граница не "перескочит" правую
    while (left_bound <= right_bound) {
        pointer = (left_bound + right_bound) / 2;

        // если мы нашли элемент,
        if (element == object[pointer])
            return pointer;

        if (element < object[pointer])
            right_bound = pointer - 1;

        else
            left_bound = pointer + 1;
    }
    
    return -1;
} 
