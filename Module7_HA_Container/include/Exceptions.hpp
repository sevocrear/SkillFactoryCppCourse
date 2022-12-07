#pragma once
#include <iostream>
#include <exception>
using namespace std;

class BadLength : public exception
{
public:
    virtual const char* what() const noexcept override   
    {
        return "ERROR: Bad Length!";
    }
};

class BadRange : public exception
{
public:
    virtual const char* what() const noexcept override   
    {
        return "ERROR: Bad Range!";
    }
};