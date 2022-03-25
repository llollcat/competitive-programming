/* Палиндром

 * Примеры:
 * Казак
А роза упала на лапу Азора
Do geese see God?
Madam, I’m Adam/ */


#include <bits/stdc++.h>

using namespace std;


bool fn(string input) {

    unsigned int p1 = 0;
    unsigned p2 = input.length() - 1;


    while (p1 <= p2) {
        while ((p1 < input.length()) && (input[p1] == ' ') && (!isalpha(input[p1])))
            ++p1;

        while ((p2 >= 0) && (input[p2] == ' ') && (!isalpha(input[p2])))
            --p2;
        if (p1 > p2)
            break;


        if (tolower(input[p1]) != tolower(input[p2]))
            return false;

        ++p1;
        --p2;


    }


    return true;
}


int main() {

    cout << fn("Kazak");


    return 0;
} 
