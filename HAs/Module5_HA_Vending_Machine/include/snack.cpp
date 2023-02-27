#include "snack.hpp"
// Snack Class
Snack::Snack(std::string name) {
            this->name = name;
        }
void Snack::getName() const {
    std::cout << this->name << std::endl;
}