#include <iostream>
using namespace std;
//Напишите функцию processArray, которая проходит в цикле по всем элементам массива и на каждой итерации вызывает функцию callback, которая принимает на вход текущий элемент массива: void processArray(int* arr, int size, void (*callback)(int));
//Также напишите две функции callback, одна из которых выводит на консоль текущий элемент массива: void showElement(int e), другая — модуль элемента массива: void showElementMod(int e).

void showElement(int a)
{
    cout << a << endl;
}

void showElementMod(int a)
{   
    if (a < 0) {
        a = - a;
    }
    cout << a << endl;
}

void processArray(int arr[], int n, void (*shower)(int))  
{  
    for (int i = 0; i < n; i++)
    {
        (*shower)(arr[i]);
    }
}  

int main()
{
    int arr[10] = {0, 1, -6, 87, -4, -7, 9, 11, -34, 2};
    
    bool show = false;
    cout << "Show type:";
    cin >> show;
    void (*shower)(int) = show ? showElement : showElementMod;

    processArray(arr, 10, shower);

    return 0;    
}