#include <bits/stdc++.h>

using namespace std;


vector<long long> vectorOfFactorizedNumber(long long number){
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
