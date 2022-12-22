#pragma once

#include <cassert> // for assert()
#include "Exceptions.hpp"

template <typename X> class IntArray
{
    int _m_length{};
    X* _m_data{};
    
public:
    IntArray(int n);

    ~IntArray();

    void erase();

    X& operator[](int index);
    
    IntArray(IntArray& a);		// Конструктор копирования
    IntArray& operator=(IntArray& a);     // Оператор присваивания 
    // reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
    void reallocate(int newLength);

    // resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
    void resize(int newLength);

    void insertBefore(X value, int index);

    void remove(int index);

    // A couple of additional functions just for convenience
    void insertAtBeginning(X value);
    void insertAtEnd(X value);

    int findElement(X value);

    int getLength() const;
};

