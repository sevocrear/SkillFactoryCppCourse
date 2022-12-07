#include "vending.hpp"

// Vending Machine

VendingMachine::VendingMachine(int slot_count) {
    this->slot_count = slot_count;
    this->slots = new SnackSlot*[slot_count];
    this->busy_num = 0;
}

void VendingMachine::addSlot(SnackSlot *slot) {
    slots[this->busy_num] = slot;
    this->busy_num++;
}

int VendingMachine::getEmptySlotsCount() const {
    int empty_slots_count = this->slot_count - this->busy_num; // Считаем невставленные слоты (пустые)    
    for (int i = 0; i < this->busy_num; i++) {
        if (this->slots[i]->getBusyNum() == 0) {
            empty_slots_count++;
        }
    }
    return empty_slots_count;
}

