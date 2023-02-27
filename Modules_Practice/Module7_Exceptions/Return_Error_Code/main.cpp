#include <iostream>
#include <climits>
using namespace std;

bool Divide(int a, int b, int& result)
{
    if (b != 0)
    {
        result = a / b;
        return true;
    }
    else
    {
        result = INT_MAX;
        return false;
    }
}

int main()
{
    int a = 4;
    int b = 0;
    int result;
    
    if (Divide(a,b, result))
    {
        cout<<"result: " << result << endl;
    }
    else
    {
        cout << "try again" << endl;
    }

    return 0;
}