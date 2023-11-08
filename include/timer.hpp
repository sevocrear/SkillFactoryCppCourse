#pragma once
#include <chrono>
#include <string>
#include <iostream>

class Timer {
    private:
        std::chrono::time_point<std::chrono::steady_clock> start_;
    public:
        void start();
        void calc(std::string name = "");
};