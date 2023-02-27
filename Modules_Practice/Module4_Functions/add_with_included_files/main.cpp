#include <iostream>
#include  "Add.h"
using namespace std;

int main(int argc, char* argv[])
{
    int a = 4;
    int b = 5;
		
    int sum = Add(a, b);
    cout << sum << endl;
    return 0;
}