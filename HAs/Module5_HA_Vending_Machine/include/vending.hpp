#pragma once
#include <iostream>
#include "slot.hpp"
// Vending Machine
class  VendingMachine {
    private:
        int slot_count, busy_num;
        SnackSlot **slots;
        ~VendingMachine(); 
    public:
        VendingMachine(int slot_count);
        int getEmptySlotsCount() const;
        void addSlot(SnackSlot *slot);
};