#include "speakers.hpp"

Speaker::Speaker(int power) : _power(power)
{
}

void Speaker::Show()
{
    std::cout << "Speaker Power: " << _power << std::endl;
}