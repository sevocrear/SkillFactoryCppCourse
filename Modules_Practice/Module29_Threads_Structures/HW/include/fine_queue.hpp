#include <iostream>
#include <queue>
#include <thread>
#include <condition_variable>
#include <shared_mutex>
#include <atomic>
#include <mutex>
#include <vector>
using namespace std;

struct Node
{
  int _value;
  Node *_next;
  std::mutex node_mutex;
  Node(int value) : _value(value), _next{nullptr} {}
};

class FineGrainedQueue
{
private:
  Node *_head;
  std::mutex queue_mutex;

public:
  FineGrainedQueue() : _head(nullptr) {}

  void push_back(int data);
  void insertIntoMiddle(int value, int pos);
};