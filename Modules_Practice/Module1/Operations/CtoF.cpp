#include <iostream>
using namespace std;

int main() {
    cout << "Введите температуру с Цельсиях" << endl;
    float celsius;
    cin >> celsius;
    cout << celsius <<  "Цельсия = " << (celsius*9)/5 + 32 << "Фаренгейт" << endl;
}