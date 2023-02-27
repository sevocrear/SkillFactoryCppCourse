#include <iostream>
#include "include/hash_table.hpp"
int main() 
{   
    HashTable ht;
    ht.add((char*)"apple", 10);
    ht.add((char*)"orange", 15);
    ht.add((char*)"banana", 2);
    ht.add((char*)"lemon", 6);
    ht.add((char*)"pear", 7);
    ht.add((char*)"ciwi", 4);
    ht.add((char*)"mandarin", 9);
    ht.del((char*)"ciwi");
    std::cout << ht.find((char*)"ciwi") << std::endl;
    return 0;
}