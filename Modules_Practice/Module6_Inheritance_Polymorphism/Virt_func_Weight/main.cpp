#include <iostream>
using namespace std;

class NonVirt
{
public:
    void Show()
    {
        cout << "NonVirt Show" << endl;
    }
};

class Virt
{
public:
    virtual void Show()
    {
        cout << "Virt Show" << endl;
    }
};

int main()
{
    NonVirt nv;
    Virt v;

    cout << "size of class with non virtual method: " << sizeof(nv) << endl;
    cout << "size of class with virtual method: " << sizeof(v) << endl;
    return 0;
}