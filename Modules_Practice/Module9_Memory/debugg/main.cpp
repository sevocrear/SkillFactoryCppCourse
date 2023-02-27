#include  <memory>
#include <iostream>
using namespace std;

bool f(weak_ptr<int> wp)
{
    if (std::shared_ptr<int> p = wp.lock())
    {
        
        *p = 7;
        return true;
    }
    
    return false;
}

int main()
{
    shared_ptr<int> sp = make_shared<int>(0);
    weak_ptr<int> wp = sp;
    
    std::shared_ptr<int> p = wp.lock();
    if (p && *p == 3)
    {
        *p = 9;
    }
    else if (f(wp))
    {
        *sp = 1;
    }
    else
    {
        int* ptr = sp.get();
        shared_ptr<int> sp1 = shared_ptr<int>(ptr);
        *sp1 = 13;
    }
    
    cout << sp.use_count() << " " << *sp << endl;
    
   return 0;
}