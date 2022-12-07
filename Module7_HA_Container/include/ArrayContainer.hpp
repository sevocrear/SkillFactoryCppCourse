#pragma once

#include <cassert> // for assert()

class IntArray
{
private:
    int _m_length{};
    int* _m_data{};

public:
    IntArray() = default;

    IntArray(int length);

    ~IntArray();

    void erase();

    int& operator[](int index);

    // reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
    void reallocate(int newLength);

    // resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
    void resize(int newLength);

    void insertBefore(int value, int index);

    void remove(int index);

    // A couple of additional functions just for convenience
    void insertAtBeginning(int value);
    void insertAtEnd(int value);

    int getLength() const;
};

