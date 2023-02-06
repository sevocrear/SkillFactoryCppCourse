#include <iostream>
#include <string>
using namespace std;

bool IsKPeriodic(const string& str, const int  k) {
    // One character strings are trivially periodic.
    if (k == 0) return false;

    if (str.length() == 1) return true;
    
    // Check if the string is divisible by k
    if (str.length() % k) return false;
    
    // Check if the string consists of k equal substrings
    size_t len = k;
    while (len < str.length()) {
        // If the substring does not match, the string is not periodic
        if (str.substr(0, k) != str.substr(len, k)) {
            return false;
        }
        len += k;
    }
    //The string is periodic
    return true;
}

int main() 
{   
    std::string str = "abab";
    cout << IsKPeriodic(str, 2) << endl;
    return 0;
}