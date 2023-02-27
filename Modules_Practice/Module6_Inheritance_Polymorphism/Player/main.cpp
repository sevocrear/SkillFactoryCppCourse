#include <iostream>
using namespace std;
// Перепишите базовые классы Device и Player так, чтобы класс Player переопределял функцию ShowSpec, и выводил на консоль сообщение с информацией о времени работы аккумулятора и количество треков, которое можно хранить в плеере.
class Device
{
public:
    Device(int batteryLife) : _batteryLife(batteryLife) 
    {
    }


    virtual void ShowSpec()
    {
        cout << "Battery Life: " << _batteryLife << endl;
    }
protected:
    int _batteryLife;
};

class Player : public Device
{
private:
     int _totalTracks;
public:
     Player(int batteryLife, int totalTracks) : Device(batteryLife), _totalTracks(totalTracks)
    {
    }

    void ShowSpec()
    {
        cout << "Battery Life: " << _batteryLife << endl;
        cout << "Total tracks: " << _totalTracks << endl;
    }

};