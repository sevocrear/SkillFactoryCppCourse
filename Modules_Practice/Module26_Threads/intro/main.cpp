#include <iostream>
#include <string>
#include <thread>
 
void write_hello()
{
    std::cout << "Thread ID = (" << std::this_thread::get_id() <<  
                 ") says Hello" << std::endl;
}
 
int main()
{
    std::thread t(write_hello);
    t.join();
    std::cout << "Main Thread ID (" << std::this_thread::get_id() <<  
                 ") says Bye" << std::endl;
    return 0;
}