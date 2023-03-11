#include <iostream>
#include <deque>
using namespace std; 
int main()
{
    std::deque<int> d = {7, 5, 16, 8};
 
    d.push_front(13);
    d.push_back(25);
    
    cout << "size: " << d.size() << endl;
    cout << "front: " << d.front() << endl;
    cout << "back: " << d.back() << endl;
    cout << "element at index 2: "<< d.at(2) << endl;
    
    cout << "elements: ";
    for(int i = 0; i < d.size(); ++i) {
        cout << d[i] << " ";
    }
    cout << endl << "elements pop from back: ";
    while (!d.empty()) {
        cout << d.back() << " ";
        d.pop_back();
    }
 return 0;
}