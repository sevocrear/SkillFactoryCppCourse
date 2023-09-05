#include <iostream>
#include <string>
#include <thread>
 
int i = 0; 
 
void func()
{
    while (1)
    {
        i++;
        i--;
        if (i != 0) exit(1);
    }
}
 
int main()
{
    std::thread t1(func);
    std::thread t2(func);
    t1.join();
    t2.join();
    return 0;
}