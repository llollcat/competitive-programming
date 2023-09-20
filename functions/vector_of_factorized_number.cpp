#include <bits/stdc++.h>

using namespace std;

/*
Возвращает вектор простых чисел, перемножив которые, можно получить изначально введённое число. Если число простое, то вернёт вектор из одного простого числа.
*/
vector<long long> vector_of_factorized_number(long long number){
    vector<long long> factorized;
    for (long long i = 2;i <= static_cast<long long>(sqrt(number)); ++i){
        while (number % i == 0){
            factorized.push_back(i);
            number /= i;
        }
    }
    if ((number != 1) || (factorized.empty())){
        factorized.push_back(number);
    }
    
    return factorized;
} 
