#pragma once 

#include "mobile_phones.hpp"
#include "speakers.hpp" 

class Yandex_Station final : public Speaker, MobilePhone
{
public:
    Yandex_Station(int power, bool nfc_pay);

    void Show() override;
};