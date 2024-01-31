#include "fine_queue.hpp"

void FineGrainedQueue::push_back(int data)
{
    Node *node = new Node(data);
    if (_head == nullptr)
    {
        _head = node;
        return;
    }
    Node *last = _head;
    while (last->_next != nullptr)
    {
        last = last->_next;
    }
    last->_next = node;
    return;
}

void FineGrainedQueue::insertIntoMiddle(int value, int pos)
{
    Node *newNode = new Node(value);
    queue_mutex.lock();
    if (!_head)
    {
        _head = newNode;
        queue_mutex.unlock();
        // debug
        lock_guard<mutex> l(queue_mutex);
        Node *ccurrent = _head;
        while (ccurrent != nullptr)
        {
            cout << ccurrent->_value << " ";
            ccurrent = ccurrent->_next;
        }
        cout << "thread id " << this_thread::get_id() << endl;
        //
        return;
    }
    if (pos == 0)
    {
        newNode->_next = _head;
        _head = newNode;
        queue_mutex.unlock();
        // debug
        lock_guard<mutex> l(queue_mutex);
        Node *ccurrent = _head;
        while (ccurrent != nullptr)
        {
            cout << ccurrent->_value << " ";
            ccurrent = ccurrent->_next;
        }
        cout << "thread id " << this_thread::get_id() << endl;
        //
        return;
    }
    Node *current = _head;
    current->node_mutex.lock();
    queue_mutex.unlock();
    int currPos = 0;
    while (currPos < pos - 1 && current->_next != nullptr)
    {
        Node *prev = current;
        current->_next->node_mutex.lock();
        current = current->_next;
        prev->node_mutex.unlock();
        currPos++;
    }
    Node *next = current->_next;
    current->_next = newNode;
    current->node_mutex.unlock();
    newNode->_next = next;
    // debug
    lock_guard<mutex> l(queue_mutex);
    Node *ccurrent = _head;
    while (ccurrent != nullptr)
    {
        cout << ccurrent->_value << " ";
        ccurrent = ccurrent->_next;
    }
    cout << "thread id " << this_thread::get_id() << endl;
    //
}