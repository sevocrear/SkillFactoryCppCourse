#include "mobile_phones.hpp"

MobilePhone::MobilePhone(bool nfc_pay) : _nfc_pay(nfc_pay)
{
}

void MobilePhone::Show()
{
    std::cout << "NFC Pay works: " << _nfc_pay << std::endl;
}

Iphone::Iphone(bool nfc_pay, std::string color) : MobilePhone(nfc_pay), _color(color)
{
}

void Iphone::Show()
{
    std::cout << _color <<" Iphone, nfc works in Russia: " << _nfc_pay << std::endl;
}

Xiaomi::Xiaomi(bool nfc_pay, std::string color, std::string os) : MobilePhone(nfc_pay), _color(color), _os(os)
{
}

void Xiaomi::Show()
{
    std::cout << _color <<" Xiaomi, nfc works in Russia: " << _nfc_pay << " os: " << _os << std::endl;
}
