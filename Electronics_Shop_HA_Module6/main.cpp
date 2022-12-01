#include "include/mobile_phones.hpp"
#include "include/speakers.hpp"
#include "include/Yandex_Station.hpp"
using namespace std;
int main()
{
    IElectronics* electronics[4];
    
    electronics[0] = new Iphone(true, string("Green"));
    electronics[1] = new Xiaomi(true, string("Green"), string("MIOU"));
    electronics[2] = new Speaker(15);
    electronics[3] = new Yandex_Station(15, false);
    
    bool open = true;
    while (open)
    {
        cout << "Выберите продукт : 1 - Iphone, 2 - Xiaomi, 3 - Колонка, 4 - Яндекс-Станция, 0 чтобы выйти" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
                electronics[0]->Show();
                break;
            
            case 2:
                electronics[1]->Show();
                break;
            
            case 3:
                electronics[2]->Show();
                break;
            
            case 4:
                electronics[3]->Show();
                break;
                
            case 0:
                open = false;
                break;
            
            default:
                cout << "Выберите продукт от 1 до 4 или 0, чтобы выйти" << endl;
            break;
        }
    }

   delete electronics[0];
   delete electronics[1];
   delete electronics[2];
   delete electronics[3];

    return 0;
}