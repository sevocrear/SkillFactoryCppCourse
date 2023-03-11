#include "kek.hpp"
#include <iostream>
using namespace std;

void ScoreTable::AddScore(const string& name, int score)
{
    // ваш код
    map <string,int>::iterator it = _table.find(name);
    if (it !=_table.end()) {
        _table[name] += score;
    }
    else {
        _table.insert({name, score});
    }

}

void ScoreTable::DeleteScore(const string& name)
{
    // ваш код   
    map <string,int>::iterator it = _table.find(name);
    if (it !=_table.end()) {
        _table.erase(it);
    }

}

void ScoreTable::PrintScore(const string& name)
{
    // ваш код   
    map <string,int>::iterator it = _table.find(name);
    if (it !=_table.end()) {
        std::cout << name << " " << it->second << std::endl;
    }
}