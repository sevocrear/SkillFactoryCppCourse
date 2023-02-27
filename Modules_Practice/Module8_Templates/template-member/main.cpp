#include <iostream>
using namespace std;

class X
{
    // Определим шаблонный класс внутри класса
    template <typename T>
    class Y  
    {
        public:
        T _mt;
        Y(T t): _mt(t) { }
    };
  
    Y<int>  yInt;  // переменная, созданная из шаблона-члена класса
    Y<char> yChar; // переменная, созданная из шаблона-члена класса

public:
    X(int i, char c) : yInt(i), yChar(c) { }
    void print()
    {
        cout << yInt._mt << " " << yChar._mt << endl;
    }
};

int main()
{
   X x(1, 'a');
   x.print();
}