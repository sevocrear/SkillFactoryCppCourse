
// Усложним пример и напишем программу, которая переводит значения из фаренгейта в цельсий или наоборот, и получает в виде аргументов командной строки тип перевода и значение которое нужно перевести:

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Введите параметр конвертации F или C и значение!" << endl;
        return 1;
    }
    if (*argv[1] == 'F')
    {
        float c = atof(argv[2]);
        float f = (9.0 * c / 5.0) + 32;
        cout << "Температура в градусах по Фаренгейту : " << f << endl;
        return 0;
    }
    else if (*argv[1] == 'C')
    {
        float f = atof(argv[2]);
        float c = ((f * 5.0) - (5.0 * 32)) / 9;
        cout << "Температура в градусах по Цельсию : " << c << endl;
        return 0;
    }
    else
    {
        cout << "Неправильно заданы параметры";
        return 1;
    }
}

