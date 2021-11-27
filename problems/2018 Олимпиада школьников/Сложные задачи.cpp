#include <bits/stdc++.h>

using namespace std;


int main() {

    string input;
    cin >> input;
    int A_counter = 0;
    for (auto &item: input) {
        if (item == 'A')
            ++A_counter;
    }
    long long sum=1;
    int answer=1;
    while (A_counter>sum+answer){
        ++answer;
        sum+=answer;
    }

    cout << answer;


    return 0;
} 
