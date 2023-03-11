#include <iostream>
#include "include/kek.hpp"
int main() 
{   
    ScoreTable score_table;
    score_table.AddScore("Ilia", 5);
    score_table.PrintScore("Ilia");

    score_table.AddScore("Ilia", 5);
    score_table.PrintScore("Ilia");
    return 0;
}