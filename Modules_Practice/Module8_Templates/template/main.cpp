#include <iostream>
using namespace std;
/**
Создайте шаблонный класс MyPair. Этот класс должен содержать два поля шаблонного типа. У класса создайте шаблонный метод getmax(), который возвращает максимальное значение из двух полей объекта типа MyPair. Используйте шаблонную функцию, которую вы создали в предыдущем юните. Напишите программу, которая напечатает максимальные значения для объектов различных типов — int, float, string.
**/
//Шаблонный класс:
template <typename X> class MyPair {
   	X a;
    X b;
public:
   	MyPair(X first, X second) {
         	a = first;
            b = second;
   	}
   	X getmax() {
        X max;
        if (a >= b) {
            max = a;
        }
        else {
            max = b;
        }
        return max;
    }
    void showmax() {
        cout << "Max value is " << getmax() << endl;
    }
};

int main() {

   	//Создание объекта с int-полем:
   	MyPair<string> a("abc", "ddd");
    a.showmax();
   	return 0;
}