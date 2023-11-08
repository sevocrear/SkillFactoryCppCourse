#include <timer.hpp>
#include <vector_func.hpp>



int main()
{
    int N, M;
    Timer timer;
    std::cout << "Введите размер массива N" << std::endl;
    std::cin >> N;
    std::cout << "Введите количество частей, на которые будет разбит массив M" << std::endl;
    std::cin >> M;

    timer.start();
    Vector vec(N);
    timer.calc("vector create");

    vec.show(10);
    timer.start();
    int sums = vec.sums(M);
    timer.calc("Sum calculation");
    std::cout << "Сумма элементов массива: " << sums << std::endl;
    // print size of vector M
    // std::cout << vec.size() << std::endl;
    return 0;

}