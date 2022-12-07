#pragma once
#include <iostream>

// Snack Class
class Snack {
    private:
        std::string name;
    public:
        Snack(std::string name);
        void getName() const;
};