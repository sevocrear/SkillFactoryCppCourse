#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v  = {0,1,2,3,4};
    vector<int>::iterator it = v.begin();
    
    it++;
    cout << *it << endl;
    
    it--;
    cout << *it << endl;

    advance(it, 3);
    cout << *it << endl;
    vector<int>::iterator it1 = prev(it);
    cout << *it1 << endl;

    vector<int>::iterator it2 = next(it);
    cout << *it2 << endl;
    return 0;
}
