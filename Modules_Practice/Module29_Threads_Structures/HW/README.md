Напишите реализацию метода insertIntoMiddle(int value, int pos) для списка мелкогранулярной блокировкой. Часть кода уже написана — сама структура списка взята из юнита про мелкогранулярную блокировку и приведена ниже.

```cpp
struct Node
{
  int value;
  Node* next;
  std::mutex* node_mutex;
};

class FineGrainedQueue
{
  Node* head;
  std::mutex* queue_mutex;
};
```

Функция должна вставить узел с переданным значением value в позицию pos. Чтобы не переусложнять реализацию, предполагается следующее:

* очередь не пустая,
* вставляется элемент в середину или конец списка, то есть вставку в начало списка не нужно рассматривать,
* если pos больше длины списка, то нужно вставить элемент в конец списка.