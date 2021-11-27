/*ограничение по времени на тест
1 секунда
ограничение по памяти на тест
256 мегабайт
ввод
стандартный ввод
вывод
стандартный вывод

При выполнении различных физических расчетов часто приходится иметь дело не только с числами, но и с размерностями величин. При этом размерности могут получаться весьма сложными и их требуется сокращать: например, размерность кг/(кг/м/с) это просто м/с.

Напишите программу, которая максимально сократит размерность и запишет все встречающиеся величины слева направо в алфавитном порядке (если размерность является дробью, то в алфавитном порядке записываются отдельно числитель и знаменатель).
Входные данные

Первая строка входного файла содержит единственную строку символов — размерность, подлежащую сокращению.

Размерности величин обозначаются латинскими строчными и заглавными буквами.

Кроме латинских букв в выражении могут присутствовать знаки умножения «*», деления «/» и круглых скобок. Степени величин выражаются кратным повторением величины. Порядок выполнения операций соответствует общепринятому. Величины, отличающиеся регистром букв считаются различными.

Длина сокращаемой размерности не превосходит 1000 символов.
Выходные данные

Выходные данные содержат сокращенную размерность. Первая строка содержит числитель размерности, вторая — знаменатель. Допустимо в виде числителя и/или знаменателя указывать единицу.
Примеры
Входные данные
Скопировать

kg/(kg/(m/s))

Выходные данные
Скопировать

m
s

Входные данные
Скопировать

kg*a/(Fs*B)*A*Kt

Выходные данные
Скопировать

A*a*Kt*kg
B*Fs

Примечание

Сортировка в алфавитном порядке подразумевает следующий порядок букв: «AaBbCbDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz». Более короткие строки стоят раньше более длинных.

*/



#include <bits/stdc++.h>

using namespace std;


typedef pair<vector<string>, vector<string> > up_and_down_pair;

up_and_down_pair pars(const string &input) {
    /* Если ( вход в новую функцию
 * Если ) выход вверх
 * Если * добавляем в массив
 * Если / меняем is_up = !is_up перед этим в массив*/

    // добавляет велечину в числитель и знаменатель.
#define push_buffer  if (!buff.empty()) {if (is_up) {up.push_back(buff);} else {down.push_back(buff);} buff.clear();}

    vector<string> up;
    vector<string> down;

    static auto iter = input.begin();
    bool is_up = true;
    string buff;
    while (iter != input.end()) {
        if ((*iter == '*') || (*iter == '/')) {
            push_buffer
            if (*iter == '/')
                is_up = false;
            else
                is_up = true;
            ++iter;

        } else if (*iter == '(') {
            push_buffer

            ++iter;
            auto returned_val = pars(input);
            if (is_up) {
                up.insert(up.end(), returned_val.first.begin(), returned_val.first.end());
                down.insert(down.end(), returned_val.second.begin(), returned_val.second.end());
            } else {
                down.insert(down.end(), returned_val.first.begin(), returned_val.first.end());
                up.insert(up.end(), returned_val.second.begin(), returned_val.second.end());
            }
            is_up = true;
        } else if (*iter == ')') {
            push_buffer
            ++iter;
            return up_and_down_pair(up, down);

        } else {
            buff += *iter;
            ++iter;
        }

    }

    push_buffer

    return up_and_down_pair(up, down);

}


int main() {

    string input;
    cin >> input;

    // происходит превращение в одну большую дробь
    auto returned_val = pars(input);
    vector<string> up = returned_val.first;
    vector<string> down = returned_val.second;

    // сокращения велечин
    for (int i = 0; i < up.size(); ++i) {
        auto temp = find(down.begin(), down.end(), up[i]);
        if (temp != down.end()) {
            up.erase(up.begin() + i);
            --i;
            down.erase(temp);

        }


    }

    // сортировка и вывод
    {
        auto sort_by_alphabetic_order = [](string a, string b) {
            static const string alphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
            for (int i = 0; i < min(a.size(), b.size()); ++i) {
                int temp1 = alphabet.find(a[i]);
                int temp2 = alphabet.find(b[i]);
                if (temp1 == temp2)
                    continue;
                return temp1 < temp2;


            }
            return a.size() < b.size();
        };
        stable_sort(up.begin(), up.end(), sort_by_alphabetic_order);
        stable_sort(down.begin(), down.end(), sort_by_alphabetic_order);

        if (up.empty())
            cout << 1;
        for (int i = 0; i < up.size(); ++i) {

            cout << up[i];
            if (i != up.size() - 1) {
                cout << '*';
            }

        }
        cout << endl;
        if (down.empty())
            cout << 1;
        for (int i = 0; i < down.size(); ++i) {

            cout << down[i];
            if (i != down.size() - 1) {
                cout << '*';
            }

        }
    }

    return 0;
}
