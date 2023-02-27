#include "node.hpp"
#include <iostream>
class List
{
public:
    List() : m_head(nullptr) {}
    void push_back(int data);
    void push_front(int data);
    void insert(int pos, int data);
    void show();
    void deleteNode(int data); 
    void deletePNode(int position);
    void clear();
private:
    Node* m_head;
};