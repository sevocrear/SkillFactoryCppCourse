#include <iostream>
#include <queue>
using namespace std;
 
int main()
{
    priority_queue<float> PrQueue;

    PrQueue.push(0.54);
    PrQueue.push(0.3);
    PrQueue.push(-0.1);
    PrQueue.push(0.93);
    PrQueue.push(0.03);
 

    while(!PrQueue.empty()) {
        cout << PrQueue.top() << endl;
        PrQueue.pop();
    }
    return 0;
}