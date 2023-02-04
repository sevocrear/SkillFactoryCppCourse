#include <iostream>
#include <string>
using namespace std;

bool IsKPeriodic(string str, int k) {
    // One character strings are trivially periodic.
    if (str.length() == 1) return true;
    
    // Check if the string is divisible by k
    if (str.length() % k) return false;
    
    // Check if the string consists of k equal substrings
    string subStr = str.substr(0, k);
    int len = k;
    while (len < str.length()) {
        // If the substring does not match, the string is not periodic
        if (subStr != str.substr(len, k)) {
            return false;
        }
        len += k;
    }
    //The string is periodic
    return true;
}

int main() 
{   
    cout << IsKPeriodic("aaaa", 1) << endl;
    return 0;
}