#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Show()
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
    Base* pderived = &derived;

    pbase->Show(); // увидим в консоли: Base Class
    pderived->Show(); // увидим в консоли: Derived Class
	
    return 0;
}