#include "vector_func.hpp"
#include <mutex>

std::mutex mutex;
Vector::Vector (int N) {
    // Randomize it
    std::mt19937 gen(42); //Standard mersenne_twister_engine seeded with 42
    std::uniform_int_distribution<> dis(1, 100);
    for(int i=0; i<N; i++) {
        array_.push_back(dis(gen)); //Generate a random integer for each element in the vector
    }
}

void Vector::show(int N) {
    std::cout << "Vector of " << array_.size() << " elements:" << std::endl;
    int size = static_cast<int>(array_.size());
    int min = std::min(N, size);
    for(int i=0; i < min; i++) {
        std::cout << this->array_[i] << " "; //Generate a random integer for each element in the vector
    }
    std::cout << "..." << std::endl;
}
void Vector::calculateSum(const std::vector<int>& vec, int start, int end, int &sums) {
    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += vec[i];
    }
    std::cout << std::endl;
    std::cout << "Sum of part " << start << "-" << end << " = " << sum << std::endl;
    mutex.lock();
    sums += sum;
    mutex.unlock();
}

int Vector::sums(int M) {
    int partSize = array_.size() / M;
    std::vector<std::thread> threads;
    int sums = 0;
    for (int i = 0; i < M; i++) {
        int start = i * partSize;
        int end = (i == M - 1) ? array_.size() : start + partSize;
        threads.push_back(std::thread(calculateSum, array_, start, end, std::ref(sums)));
    }
    for (auto &t : threads) {
        t.join();
    }
    return sums;
}