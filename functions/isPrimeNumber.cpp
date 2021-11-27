#include <bits/stdc++.h>

using namespace std;


bool isPrimeNumber(long long number){
    for (long long i= 2; i <= static_cast<long long>(sqrt(number)); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    
    return true;
}
