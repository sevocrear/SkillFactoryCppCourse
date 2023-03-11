#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    std::vector<int>::iterator it = v.begin() + 3; 
    
    std::vector<int>::iterator newIt = v.insert(it, 99);
    
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    
    cout << endl;
    
    v.erase(newIt);
    
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
 return 0;
}