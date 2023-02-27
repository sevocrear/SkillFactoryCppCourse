// SnackSlot Class
#include "slot.hpp"

SnackSlot::SnackSlot(int slot_size) {
        this->slot_size = slot_size;
        slot = new Snack*[slot_size];
        this->busy_num = 0;
    }
void SnackSlot::getSlot() const {
    for (int i = 0; i < this->busy_num;i++) {
        slot[i]->getName();
    }
    for (int i = this->busy_num;(i < this->slot_size);i++) {
        std::cout << "Empty" << std::endl;
    }
}

int SnackSlot::getBusyNum() const {
    return this->busy_num;
}

SnackSlot::~SnackSlot() {
    delete this->slot;
}


void SnackSlot::addSnack(Snack *snack) {
    slot[this->busy_num] = snack;
    this->busy_num++;
}