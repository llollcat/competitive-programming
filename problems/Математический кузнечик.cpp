/*ограничение по времени на тест
1 секунда
ограничение по памяти на тест
256 мегабайт
ввод
стандартный ввод
вывод
стандартный вывод

Математический кузнечик расположился на числовой оси в точке с координатой x0

.

От нечего делать он начинает прыгать по точкам оси с целочисленными координатами. Прыжок из точки с координатой x
на расстояние d влево перемещает кузнечика в точку с координатой x−d, а вправо — в точку с координатой x+d

.

Кузнечик очень любит целые положительные числа, и поэтому для каждого i
от 1 и дальше в i-ю минуту нахождения на оси совершает прыжок на расстояние ровно i. Иными словами, сначала он прыгает на 1, потом на 2

и так далее.

Направление прыжка кузнечик определяет следующим образом: если точка, на которой кузнечик находится перед прыжком, имеет четную координату, кузнечик прыгает влево, иначе — вправо.

Например, находясь после 18
прыжков в точке с координатой 7, кузнечик прыгнет на расстояние 19 вправо, так как 7 — нечетное число, и окажется в точке 7+19=26. Так как число 26 четно, следующий прыжок на расстояние 20 кузнечик сделает влево, и окажется в точке 26−20=6

.

Определите, в какой точке окажется кузнечик через ровно n

прыжков.
Входные данные

В первой строке ввода дано целое число t
(1≤t≤104

) — количество наборов входных данных.

В каждой из следующих t
строк дано по два целых числа x0 (−1014≤x0≤1014) и n (0≤n≤1014

) — координата начального положения кузнечика и количество прыжков.
Выходные данные

Выведите t
строк. В i-й строке выведите одно целое число — ответ на i-й набор входных данных — координату точки, в которой будет находиться кузнечик, сделав n прыжков из точки x0

.
Пример
Входные данные
Скопировать

9
0 1
0 2
10 10
10 99
177 13
10000000000 987654321
-433494437 87178291199
1 0
-1 1

Выходные данные
Скопировать

-1
1
11
110
190
9012345679
-87611785637
1
0

Примечание

Первые два набора в примере соответствуют первым двум прыжкам из точки x0=0

.

Поскольку 0
 — четное число, первый прыжок длины 1 совершается влево, и кузнечик оказывается в точке 0−1=−1

.

Затем, так как −1
 — нечетное число, прыжок длины 2 происходит направо, приводя кузнечика в точку с координатой −1+2=1. 
*/

#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; ++i) {
        long long x, n;
        std::cin >> x >> n;
        long long temp = n + 1;
        if (!(n % 4))
            temp = 0;
        else if (n % 4 == 1)
            temp = -1 * n;
        else if (n % 4 == 2)
            temp = 1;

        std::cout << x + temp * (1 - 2 * (x & 1)) << '\n';
    }
    return 0;
}
