#pragma once
#include <thread>
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
class Vector {
    private:
        std::vector<int> array_;
        static void calculateSum(const std::vector<int>& vec, int start, int end, int &sums);
    public:
        Vector(int N);
        int sums(int M);
        void show(int N);

};