#pragma once
#include "IElectronics.hpp"

class Speaker :virtual public IElectronics
{
public:
   Speaker(int power);

void Show() override;
protected:int _power;
};