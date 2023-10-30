#include <iostream>
#include <string>
#include <thread>

void print_sum(int p1, int p2, int p3)
{
    std::cout << "Sum = " << p1 + p2 + p3 << std::endl;
}

int main()
{
    int a = 3, b = 4, c = 5;
    std::thread t(print_sum, a, b, c);
    t.join();
    return 0;
}