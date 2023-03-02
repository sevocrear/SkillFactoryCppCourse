#pragma once
#include <iostream>
#include <string.h>

#define NAMELENGTH 10  // Зафикcируем длину login

typedef char LoginName[NAMELENGTH]; // тип имя фрукта

class HashTable { // хэш таблица
    public:
    
        HashTable();
        ~HashTable();
        void add(LoginName login, std::string pass);
        void del(LoginName login);
        std::string find(LoginName login);

    private:
    
        enum enPairStatus {
            free,
            engaged,
            deleted
        };
    
        struct Pair { // пара ключ-значение
            
            Pair(): 
                login(""), 
                password(""),
                status(enPairStatus::free)
            {}
            Pair(LoginName log, std::string pass): 
                password(pass),
                status(enPairStatus::engaged) {
                    memcpy(login, log, NAMELENGTH);
            }
            Pair& operator = (const Pair& other) {
                password =  other.password;
                memcpy(login, other.login, NAMELENGTH);
                status = other.status;
                return *this;
            }
            
            bool operator == (const Pair& other) {
                return  status == other.status &&
                        (status != enPairStatus::engaged || (password == other.password && !strcmp(login, other.login)));
            }
            
            LoginName login;
            std::string password;
            
            enPairStatus status;
        };
        void resize();
        int hash_func(LoginName login, int offset);
        std::string hash_pass(std::string pass);
        Pair* array;
        int mem_size;
        int count;
};