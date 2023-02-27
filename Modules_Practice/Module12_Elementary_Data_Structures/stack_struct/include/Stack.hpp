#include <iostream>
#pragma once
using namespace std;
 
#define MAX 1000
 
class Stack {
private:
    int m_top;
 
public:
    int m_items[MAX]; 
    Stack() : m_top(-1) {}
    bool push(int x);
    int pop();
    int peek();
    bool isFull();
    bool isEmpty();
};