#include "list.hpp"

void List::push_back(int data)
{
    // создаем новый узел
    Node *node = new Node(data);
    // если список пуст, возвращаем узел
    if (m_head == nullptr)
    {
        m_head = node;
        return;
    }
    // в цикле ищем последний элемент списка
    Node *last = m_head;
    while (last->m_next != nullptr)
    {
        last = last->m_next;
    }
    // Обновляем указатель next последнего узла на указатель на новый узел
    last->m_next = node;
    return;
}

void List::push_front(int data)
{
    Node *node = new Node(data);
    node->m_next = m_head;
    m_head = node;
}

void List::insert(int pos, int data)
{
    // создаем новый узел
    Node *newNode = new Node(data);
    if (m_head == nullptr)
    {
        // если список пуст, новый узел и будет началом списка
        m_head = newNode;
        return;
    }

    if (pos == 0)
    {
        // крайний случай - вставка  в начало списка
        newNode->m_next = m_head;
        m_head = newNode;
        return;
    }

    int currPos = 0;

    Node *current = m_head;
    // в цикле идем по списку, пока список не кончится, или пока не дойдем до позиции
    while (currPos < pos - 1 && current->m_next != nullptr)
    {
        current = current->m_next;
        currPos++;
    }
    // меняем указатель на следующий узел на указатель на новый узел
    Node *next = current->m_next;
    current->m_next = newNode;
    // связываем список обратно, меняем указатель на узел, следующий после нового узла, на указатель на узел, следующий за current
    newNode->m_next = next;
}

void List::show()
{
    Node *cur = m_head;
    while (cur->m_next != nullptr)
    {
        std::cout << cur->m_data;
        cur = cur->m_next;
    }
    std::cout << cur->m_data;
}
void List::deleteNode(int data)
{
    Node *temp = m_head;
    Node *prev = nullptr;

    // крайний случай удаления начала списка
    if (temp && temp->m_data == data)
    {
        m_head = temp->m_next;
        delete temp;
        return;
    }
    // идем по списку, пока не найдем узел со значением данных, равных ключу
    while (temp && temp->m_data != data)
    {
        prev = temp;
        temp = temp->m_next;
    }
    // если узел не найден, возвращаем
    if (!temp)
        return;
    // меняем указатель следующего узла для предыдущего узла на узел, следующий за удаляемым узлом, и удаляем узел с данными
    prev->m_next = temp->m_next;
    delete temp;
}

void List::deletePNode(int position)
{
    // ваш код
    Node *temp = m_head;
    Node *prev = nullptr;

    // крайний случай удаления начала списка
    if (position == 0)
    {
        m_head = temp->m_next;
        delete temp;
        return;
    }
    // идем по списку, пока не найдем узел со значением данных, равных ключу
    int idx = 0;
    while (temp && idx < position)
    {
        prev = temp;
        temp = temp->m_next;
        idx++;
    }

    // если узел не найден, возвращаем
    if (!temp)
        return;
    // меняем указатель следующего узла для предыдущего узла на узел, следующий за удаляемым узлом, и удаляем узел с данными
    prev->m_next = temp->m_next;
    delete temp;
}

void List::clear()
{
    Node *cur = m_head;
    Node *next = nullptr;
    while (cur != nullptr)
    {
        next = cur->m_next;
        delete cur;
        cur = next;
    }
    m_head = nullptr;
}