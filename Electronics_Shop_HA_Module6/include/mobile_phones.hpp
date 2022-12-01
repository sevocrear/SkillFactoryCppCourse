#pragma once
#include "IElectronics.hpp"

class MobilePhone :virtual public IElectronics
{
public:
   MobilePhone(bool nfc_pay);

void Show() override;
protected:bool _nfc_pay;
};

class Iphone final :public MobilePhone
{
public:
    Iphone(bool nfc_pay, std::string color);
void Show() override;
private:
    std::string _color;
}; 

class Xiaomi final :public MobilePhone
{
public:
    Xiaomi(bool nfc_pay, std::string color, std::string os);
void Show() override;
private:
    std::string _color, _os;
}; 