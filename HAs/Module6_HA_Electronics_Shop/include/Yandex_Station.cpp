#include "Yandex_Station.hpp"

Yandex_Station::Yandex_Station(int power, bool nfc_pay) : Speaker(power), MobilePhone(nfc_pay)
{
}

void Yandex_Station::Show()
{
        std::cout << "Yandex_Station: power " << _power << " nfc pay " << _nfc_pay << std::endl;
}