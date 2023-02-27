#include <iostream>
using namespace std;

int main() {
    cout << "Enter the number of the day" << endl;
    int day_num;
    cin >> day_num;
    switch (day_num)
    {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    case 7:
        cout << "Sunday" << endl;
        break;
    default:
        cout << "There is no such day" << endl;
        break;
    }
    return 0;
}