#include <bits/stdc++.h>

using namespace std;


vector<long long> vectorOfFactorizedNumber(long long number){
    vector<long long> factors;
    for (long long i = 2;i <= static_cast<long long>(sqrt(number)); ++i){
        while (number % i == 0){
            factors.push_back(i);
            number /= i;
        }
    }
    if ((number != 1) || (factors.empty())){
        factors.push_back(number);
    }
    return factors;
} 
