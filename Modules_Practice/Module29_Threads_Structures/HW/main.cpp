#include "include/fine_queue.hpp"

int main()
{
    FineGrainedQueue FGQ;
    int size = 10;
    for (size_t i = 0; i < size; i++)
    {
        FGQ.push_back(5);
    }

    vector<thread> threads;
    for (int i = 0; i < 8; i++)
    {
        threads.push_back(thread([&FGQ, i]()
                                 { FGQ.insertIntoMiddle(i, i); }));
    }

    for (auto &i : threads)
    {
        i.join();
    }

    return 0;
}