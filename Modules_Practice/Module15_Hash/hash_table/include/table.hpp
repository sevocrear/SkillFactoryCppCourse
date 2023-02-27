#pragma once

#include <string.h>

#define NAMELENGTH 10  // Зафикируем длину имени
typedef char FruitName[NAMELENGTH]; // тип имя фрукта

class HashTable { // Хеш-таблица

    public: 
        HashTable();
        ~HashTable();
        void add(FruitName fr_name, int fr_count);
        void resize();
        
        void del(FruitName fr_name);
        int find(FruitName fr_name);
        
    private:
        struct ChainNode { // узел в цепочке
            FruitName fruit_name; // ключ
            int fruit_count; // значение
            
            ChainNode* next; // указатель на следующий узел в цепочке
            ChainNode(FruitName _fn, int _fc): 
              fruit_count(_fc) {
                strcpy(fruit_name, _fn);
                next = nullptr;           
            }
            ~ChainNode() {
                // удаляем друг за дружкой
                if(next != nullptr)
                    delete next;
            }
        };
        // хеш-функция для поиска индекса цепочки
        int hash_func(FruitName fr_name);
     
        ChainNode** chain_tops; // массив указателей на цепочки
        int mem_size; // количество выделенной памяти
        int count; // колиество добавленных пар ключ-значение
        
};
