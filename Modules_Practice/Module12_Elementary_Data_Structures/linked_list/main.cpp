#include <iostream>
#include "include/list.hpp"
int main() 
{   
    List list;
    list.push_back(1);
    list.push_back(5);
    list.show();
    list.clear();
    return 0;
}
