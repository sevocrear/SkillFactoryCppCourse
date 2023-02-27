#include "table.hpp"
#include "iostream"
HashTable::HashTable() {
    // выделение памяти, инициализация
    mem_size = 8;  
    chain_tops = new ChainNode*[mem_size];
    for(int i=0; i<mem_size; i++) {
        chain_tops[i] = nullptr;
    }
    count = 0;
}
HashTable::~HashTable() {
    // прибираем за собой
    for(int i=0; i<mem_size; i++) 
        if(chain_tops[i] != nullptr)
            delete chain_tops[i];
    delete[] chain_tops;
}
int HashTable::hash_func(FruitName fr_name) {
    // вычисляем индекс
    int sum = 0, i = 0;
    for(; i<strlen(fr_name); i++) {
        sum += fr_name[i];
    }
    // метод деления
    return sum % mem_size; // значение точно будет между 0 и memsize
}
void HashTable::add(FruitName fr_name, int fr_count) {
    // пересчет таблицы, если много элементов внутри
    // боремся с коллизиями
    if(count / mem_size > 3)
        resize();
    int index = hash_func(fr_name); // вычислили индекс в массиве
    if(chain_tops[index] != nullptr) {
        /* если цепока с таким индексом уже есть, то
        создаем новый узел и делаем его верхним */
        ChainNode* newNode = new ChainNode(fr_name, fr_count);
        newNode->next = chain_tops[index];
        chain_tops[index] = newNode;
    } else {
        // если нет цепочки с таким хешем
        chain_tops[index] = new ChainNode(fr_name, fr_count);
    }
    count++;
}

void HashTable::resize() {
    ChainNode** save_ct = chain_tops; // запоминаем старый массив
    int oldSize = mem_size;

    mem_size *= 2;  // увеличиваем размер в два раза  
    count = 0; // обнуляем количество элементов
    chain_tops = new ChainNode*[mem_size]; // выделяем новую память
    for(int i=0; i<mem_size; i++) {
        chain_tops[i] = nullptr;
    }
    
    for(int i =0; i<oldSize; i++) {
        ChainNode* current = save_ct[i];
        while(current != nullptr) {
            // пересчитываем хеши и добавляем в новый массив
            add(current->fruit_name, current->fruit_count);
            current = current->next;
        }
        // чистим за собой
        delete current;
    }
    // чистим за собой
    delete [] save_ct;
}

void HashTable::del(FruitName fr_name) {
    // Ваш код
    int index = hash_func(fr_name);
    if (chain_tops[index] != 0) {
        ChainNode* nodes = chain_tops[index];
        while (nodes != nullptr) {
            if (strcmp(fr_name, nodes->fruit_name) == 0) {
                delete nodes;
            }
            nodes = nodes->next;
        }
    }
}
int HashTable::find(FruitName fr_name) {
    // вернуть нужно значение, соответствующее ключу fr_name
    // если такого ключа нету в таблице, то верните -1
    // Ваш код
    int index = hash_func(fr_name);
    if (chain_tops[index] != 0) {
        ChainNode* nodes = chain_tops[index];
        while (nodes != nullptr) {
            if (strcmp(fr_name, nodes->fruit_name) == 0) {
                return nodes->fruit_count;
            }
            nodes = nodes->next;
        }
    }
    return -1;
}