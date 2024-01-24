#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

void threadfunc(promise<int>& p) {
    cout << "setting result to promise: 10" << endl;
    // установка значения в промис, фьючерс перейдёт в готовое состояние
    p.set_value(10);
    this_thread::sleep_for(chrono::seconds(2));
    cout << "thread finished work" << endl;
}

int main()
{
    // объявляем промис и передаём в поток
    promise<int> p;
    thread t(threadfunc, std::ref(p));
    // получаем фьючерс из промиса
    future<int> f = p.get_future();
    // далее ждём результат по обычным правилам
    try {
        cout << "Future result: " << f.get() << endl;
        // что-то сделали с результатом
    } catch (...) {
        cout << "Some error in thread" << endl;
    }

    t.join();

    return 0;
}