#include "timer.hpp"

void Timer::start() {
    start_ = std::chrono::steady_clock::now();
}
void Timer::calc(std::string name) {
    auto stop_ = std::chrono::steady_clock::now();
    // Calculate the time elapsed
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop_ - start_);

    // Print the time elapsed
    std::cout << "Time elapsed of func \x1B[34m`" << name << "`\033[0m : " << elapsed.count() << " milliseconds" << std::endl;
}
