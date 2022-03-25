/*массив из 0 и 1.
мы удаляем ровно один элемента
какой максимольный длины может получиться подпоследовательность из 1
[1, 0, 1, 1, 0, 0, 1] -> [1, 1, 1, 0, 0, 1] => 3*/


#include <bits/stdc++.h>

using namespace std;


int fn(string &subsequence) {
    int out = 0;

    int previous_counter = 0;
    int counter = 0;

    for (char &i: subsequence) {
        if (i == '0') {
            out = max(out, previous_counter + counter);
            previous_counter = counter;
            counter = 0;

        } else {
            ++counter;

        }


    }
    out = max(out, counter + previous_counter);

    return out;
}


int main() {
    string input;
    cin >> input;
    cout << fn(input);


    return 0;
}
