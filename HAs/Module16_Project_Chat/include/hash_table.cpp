#include "hash_table.hpp"

HashTable::HashTable() {
    count = 0;
    mem_size = 10;
    array = new Pair [mem_size];
}
HashTable::~HashTable() {
    delete[] array;
}

int HashTable::hash_func(LoginName login, int offset) {
    // вычисляем индекс
    int sum = 0, i = 0;
    for(; i < strlen(login); i++) {
        sum = sum*25 + login[i]; // метод умноженя
    }
    // второе хеширование
    int f2 = sum % (mem_size * 2);
    // проба
    return (sum % mem_size + offset*offset) % mem_size; // квадратичны метод составления хэш-таблицы 
}  

std::string HashTable::hash_pass(std::string pass) {
    unsigned int hash = 5381;
    for (int i = 0; i < pass.length(); i++) {
        hash = ((hash << 5) + hash) + pass[i];
    }
    return std::to_string(hash);
}

void HashTable::del(LoginName login) {
    // Ваш код
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for(;i < mem_size; i++) {
        index = hash_func(login, i);
        if(array[index].status != enPairStatus::deleted) { 
            if (strcmp(login, array[index].login) == 0) {
                array[index].status = enPairStatus::deleted;
            }
        }
    }
}
std::string HashTable::find(LoginName login) {
    // вернуть нужно значение, соответствующее ключу login
    // если такого ключа нету в таблице, то верните ""
    // Возвращает хэш от пароля
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for(;i < mem_size; i++) {
        index = hash_func(login, i);
        if(array[index].status == enPairStatus::engaged) { 
            // найдена пустая ячейка, занимаем ее
            if (strcmp(login, array[index].login) == 0) {
                return array[index].password;
            }
        }
    }
    return "";
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
            add(old_pair.login, old_pair.password);
        }
    }
    
    delete[] save;
}
void HashTable::add(LoginName login, std::string pass) {
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for(;i < mem_size; i++) {
        index = hash_func(login, i);
        if(array[index].status == enPairStatus::free) { 
            // найдена пустая ячейка, занимаем ее
            break;
        }
        else if (array[index].status == enPairStatus::engaged) { 
            std::cout << "Такой пользователь уже есть" << std::endl;
        }
    }

    if(i >= mem_size) {
        resize();
        add(login, pass);
    } else {
        std::string hashpass = hash_pass(pass);
        array[index] = Pair(login, hashpass);
        count++;        
    }
}