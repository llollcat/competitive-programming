/*
 *ограничение по времени на тест
0.5 second
ограничение по памяти на тест
256 megabytes
ввод
стандартный ввод
вывод
стандартный вывод

зАЧЕМ НУЖНА КЛАВИША cAPS lOCK?

Caps Lock — клавиша компьютерной клавиатуры, предназначенная для автоматической (постоянной) смены регистра букв со строчных на прописные. Будучи случайно нажатой, она приводит к последствиям вроде первого абзаца в условии этой задачи.

Будем считать, что слово набрано с ошибочно нажатой клавишей Caps Lock, если:

    либо оно полностью состоит из прописных букв;
    либо прописными являются все его буквы, кроме первой. 

В таком случае, нужно автоматически поменять регистр всех букв на противоположный. Например, регистр букв слов «hELLO», «HTTP», «z» должен быть изменен.

Напишите программу, которая применяет описанное выше правило или оставляет слово без изменения, если оно не применимо.
Входные данные

В первой строке входных данных записано слово, состоящее из прописных или строчных букв латинского алфавита. Длина слова — от 1 до 100 символов включительно.
Выходные данные

Выведите результат обработки данного слова.
Примеры
Входные данные
Скопировать

cAPS

Выходные данные
Скопировать

Caps

Входные данные
Скопировать

Lock

Выходные данные
Скопировать

Lock

*/

#include <bits/stdc++.h>

using namespace std;


int main() {

    string temp;
    cin >> temp;

    bool need_change = true;
    for (auto item  : temp.substr(1, temp.length()-1)) {
        if ((item >= 'a') && (item <= 'z')) {
            need_change = false;
        }


    }

    for (auto item  : temp) {
        if (need_change){
            if ((item >= 'a') && (item <= 'z'))
                cout << char(item - 'a'+ 'A');
            else
                cout << char(item + 'a'- 'A');
        } else
            cout << item;


    }


    return 0;
}
