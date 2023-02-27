#include <iostream>
using namespace std;

class Base
{
public:
    void Show()
    {
        cout << "Base Class" << endl;
    }
};

class Derived : public Base
{
public:
    void Show()
    {
        cout << "Derived Class" << endl;
    }
};

int main()
{
    Base base;
    Derived derived;
    Base* pbase = &base;
    Base* pderived = &derived; // Присваиваем указателю на базовый класс адрес дочернего класса Derived

    pbase->Show(); // увидим в консоли: Base Class 
    pderived->Show(); // увидим в консоли: Base Class
	
    return 0;
}