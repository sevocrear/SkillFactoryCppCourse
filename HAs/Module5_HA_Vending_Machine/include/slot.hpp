#pragma once
#include "snack.hpp"

// SnackSlot Class
class SnackSlot {
    private:
        int slot_size;
        int busy_num;
        Snack **slot;
        ~SnackSlot(); 
    public:
        SnackSlot(int slot_size);
        void getSlot() const;
        int getBusyNum() const;
        void addSnack(Snack *snack);
};