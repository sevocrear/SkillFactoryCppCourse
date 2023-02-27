#include <iostream>
using namespace std;

int fib(int n) 
{ 
    if (n <= 1) 
    {
        return n; 
    }

    return fib(n-1) + fib(n-2); 
} 

int main() 
{  
    for (int i = 0; i < 10; ++i) 
    { 
        cout << fib(i) << endl;
    }

    return 0 ;
}