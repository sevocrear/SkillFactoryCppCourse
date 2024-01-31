#include <thread>
#include <iostream>
#include <mutex>

std::mutex mutex;
static int counter = 0;

void add()
{
  for (int i = 0; i < 100000000; i++)
  {
    mutex.lock();
    counter++;
    mutex.unlock();
  }
}

void subtraction()
{
  for (int i = 0; i < 100000000; i++)
  {
    mutex.lock();
    counter--;
    mutex.unlock();
  }
}

int main()
{
  std::thread th1(add);
  std::thread th2(subtraction);

  th1.join();
  th2.join();

  std::cout << counter << std::endl;

  return 0;
}