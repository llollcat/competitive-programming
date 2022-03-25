/*Заменить последовательности пробелов в строке на одиночные пробелы. O(n) по времени, O(1) по памяти.
> normalize("some    string  ")
"some string "
"aaa"
"a"
 */

#include <bits/stdc++.h>

using namespace std;


void normalize(string &input) {
    int pointer = 0;
    bool is_previous_char_space = false;
    for (int i = 0; i < input.size(); ++i) {
        if (!((input[i] == ' ') && (is_previous_char_space))) {
            input[pointer] = input[i];
            ++pointer;

        }
        is_previous_char_space = (input[i] == ' ');


    }
    input.resize(min(pointer,static_cast<int>(input.size())));
}


int main() {
    string input;
    getline(cin, input);
    normalize(input);
    cout << input;


    return 0;
}
 
