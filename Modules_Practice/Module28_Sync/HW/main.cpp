#include <future>
#include <thread>
#include <iostream>
#include <chrono>
#include <random>

bool make_thread = true;

// Доработайте алгоритм merge sort, описанный в 11 модуле, сделав его многопоточным.
// Используйте std::futurez в качестве инструмента для синхронизации результата работы потоков.
// Нужно определить независимые части алгоритма, которые могут быть распараллелены и запустить их вычисление в отдельных потоках, как это было сделано в юните 28.7.
// Потоки могут быть запущены через std::thread или std::async, но синхронизация строго через std::future. Также предусмотрите ограничение количества запускаемых потоков по примеру из юнита 28.7.

void merge(std::vector<int>& arr, long l, long m, long r)
{
    long nl = m - l + 1;
    long nr = r - m;

    // создаем временные массивы
    int* left = new int[nl];
    int* right = new int[nr];
  //  long left[nl];
  //  long right[nr];

    // копируем данные во временные массивы
    for (long i = 0; i < nl; i++)
        left[i] = arr[l + i];

    for (long j = 0; j < nr; j++)
        right[j] = arr[m + 1 + j];

    long i = 0, j = 0;
    long k = l;  // начало левой части

    while (i < nl && j < nr) {
        // записываем минимальные элементы обратно во входной массив
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // записываем оставшиеся элементы левой части
    while (i < nl) {
        arr[k] = left[i];
        i++;
        k++;
    }
    // записываем оставшиеся элементы правой части
    while (j < nr) {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left, right;
}

void mergeSort(std::vector<int>& array, long l, long r)
{
    if (l >= r)
    {
        return;
    }
    else {

        long m = 0;

          //  m = (r + l-1) / 2;
            m = (r + l) / 2; //середина массива

        if (make_thread && (r - l > 100000))
        {
            // если элементов в левой части больше чем 10000
            // вызываем асинхронно рекурсию для правой части arr, l, m
            auto f = std::async(std::launch::async, [&]() {
                mergeSort(array, l, m);
                });

            mergeSort(array, m + 1, r);
        }
        else {
            // запускаем обе части синхронно
            mergeSort(array, l, m);

            mergeSort(array, m + 1, r);
        }

        merge(array, l, m, r);
    }


}

// Вывести массив
void print_array(const std::vector<int>& array)
{
    if (array.size() < 20) {
        for (int i: array)
            std::cout << i << " ";
    } else {
        for (int i = 0; i < 10; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << "... ";
        for (int i = array.size()-10; i < array.size(); i++) {
            std::cout << array[i] << " ";
        }
    }
    std::cout << std::endl;
}


bool check_sort(std::vector<int> array) {
    for (long i = 0; i < array.size()-1; i++) { //проверка правильности сортировки
        if (array[i] > array[i + 1]) {
            std::cout << "Unsorted " << i << std::endl;
           break;
        }
    }
}
int main()
{
    std::srand(0);
    long arr_size = 40;
    std::vector<int> array;
    // int *array = new int[arr_size]; // создали массив

    for (long i = 0; i < arr_size; i++) { //заполнили числами
      array.push_back(std::rand() % 5000);
    }
    std::vector<int> array_mono(array);

    time_t start, end;

    std::cout << "Unsorted:" << std::endl;
    print_array(array);

    // многопоточный запуск
    std::time(&start);
    mergeSort(array, 0, arr_size); //функция сортировки
    std::time(&end);

    std::cout << "Sorted (Multi-Thread):" << std::endl;
    print_array(array);

    double seconds = std::difftime(end, start);
    std::printf("The time: %f seconds\n", seconds);

    check_sort(array);
    for (long i = 0; i < arr_size; i++) { //заполнили еще раз числами
        array[i] = std::rand() % 5000;
    }

    // однопоточный запуск
    make_thread = false;
    std::time(&start);
    mergeSort(array_mono, 0, arr_size);
    std::time(&end);
    std::cout << "Sorted (One Thread):" << std::endl;
    print_array(array_mono);
    check_sort(array_mono);
    seconds = std::difftime(end, start);
    std::printf("The time: %f seconds\n", seconds);

    return 0;
}