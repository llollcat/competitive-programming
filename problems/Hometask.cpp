/*Time limit: 1 second

Memory limit: 256 megabytes
Kolya is still trying to pass a test on Numbers Theory. The lecturer is so desperate about Kolya’s
knowledge that she gives him the same task every time.

The problem is to check if N ! is divisible by N 2.
Input

The first line of input contains the only integer N (1 ≤ N ≤ 109).
Output

Please, print to output “YES” provided that N ! is divisible by N 2, otherwise print “NO”.
Examples
stdin stdout
3 NO
9 YES
Note
N ! = 1 · 2 · . . . · N*/



#include <bits/stdc++.h>
 
using namespace std;
 
 
vector <int> factorize(int x){
    vector <int> factors;
    for (int i = 2;i <= sqrt(x);i++){
        while(x % i == 0){
            factors.push_back(i);
            x /= i;
        }
    }
    if (x != 1){
        factors.push_back(x);
    }
    return factors;
}
int main() {
 
    int input;
    cin >> input;
 
    auto numbers = factorize(input);
 
    if (input==1) {
        cout << "YES";
        return 0;
    }
}
