#include <iostream>
using namespace std;

int main()
{
    int result = 0;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            result += 1;
        }
    }
    cout << result << endl;
    return 0;
}