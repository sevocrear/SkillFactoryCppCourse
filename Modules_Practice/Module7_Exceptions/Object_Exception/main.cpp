#include <iostream>
#include <climits>
using namespace std;

class BadDivision
{
private:
    int _a;
    int _b;
    
public:
    BadDivision(int a = 0, int b = 0) : _a(a), _b(b) {}
    void Show()
    {
        cout << "ERROR: Bad Division result!" << endl;
        cout << "Arguments are: a = " << _a << ", b = " << _b << endl;
    }
};

int Divide(int a, int b)
{
    if (b == 0)
    {
        throw BadDivision(a, b);
    }
	
    return a / b;
}

int main()
{
    int a = 4;
    int b = 0;

    try 
    {
        int result = Divide(a,b);
        cout << "Division result: " << result << endl;
    }
    catch(BadDivision& bd)
    {
        bd.Show();
        cout << "Exception handled!" << endl;
    }


    return 0;
}