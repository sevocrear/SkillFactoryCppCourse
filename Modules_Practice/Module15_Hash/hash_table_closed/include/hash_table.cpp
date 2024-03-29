#include "hash_table.hpp"

HashTable::HashTable() {
    count = 0;
    mem_size = 8;
    array = new Pair [mem_size];
}
HashTable::~HashTable() {
    delete[] array;
}

int HashTable::hash_func(FruitName fr_name, int offset) {
    // вычисляем индекс
    int sum = 0, i = 0;
    for(; i<NAMELENGTH; i++) {
        sum += fr_name[i];
    }
    // линейные пробы
    return (sum % mem_size + offset) % mem_size; 
}  

void HashTable::del(FruitName fr_name) {
    // Ваш код
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for(;i < mem_size; i++) {
        index = hash_func(fr_name, i);
        if(array[index].status != enPairStatus::deleted) { 
            if (strcmp(fr_name, array[index].fruit_name) == 0) {
                array[index].status = enPairStatus::deleted;
            }
        }
    }
}
int HashTable::find(FruitName fr_name) {
    // вернуть нужно значение, соответствующее ключу fr_name
    // если такого ключа нету в таблице, то верните -1
    // Ваш код
    // Ваш код
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for(;i < mem_size; i++) {
        index = hash_func(fr_name, i);
        if(array[index].status == enPairStatus::engaged) { 
            // найдена пустая ячейка, занимаем ее
            if (strcmp(fr_name, array[index].fruit_name) == 0) {
                return array[index].fruit_count;
            }
        }
    }
    return -1;
}

void HashTable::resize() {
    
    Pair* save = array;
    int save_ms = mem_size;
    
    mem_size *= 2;
    array = new Pair[mem_size];
    count = 0;
    
    for(int i=0; i<save_ms; i++) {
        Pair& old_pair = save[i];
        if(old_pair.status == enPairStatus::engaged) {
            add(old_pair.fruit_name, old_pair.fruit_count);
        }
    }
    
    delete[] save;
}
void HashTable::add(FruitName fr_name, int fr_count) {
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for(;i < mem_size; i++) {
        index = hash_func(fr_name, i);
        if(array[index].status == enPairStatus::free) { 
            // найдена пустая ячейка, занимаем ее
            break;
        }
    }

    if(i >= mem_size) {
        resize();
        add(fr_name, fr_count);
    } else {
        array[index] = Pair(fr_name, fr_count);
        count++;        
    }
}