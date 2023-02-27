#include <string>
#include <fstream>  // работа с файлами
#include <iostream>
#include <cstdlib> // для получения рандомных чисел
#include <ctime>
#include <chrono>

using namespace std;

void write_arr(const string& filename, const int*  arr, const int n)
{
    fstream fs;

    fs.open(filename, fstream::out);
    if(fs.is_open()) // проверяем, что файл успешно открыт
    {
       fs << n << '\n';  // записываем размер массива
       for (int i = 0; i < n; i++)
           fs << arr[i] << ' '; // записываем значения через пробел
       fs << '\n';

       fs.close(); // закрываем файл
    }
}

void read_arr(const string& filename, int*& arr, int& n)
{
    fstream fs;
 
    fs.open(filename, fstream::in);
    if(fs.is_open()) // проверяем, что файл успешно открыт
    {
       fs >> n;  // читаем размер массива
       arr = new int[n];
       for (int i = 0; i < n; i++)
           fs >> arr[i]; // читаем из файла разделительные символы - пробел и перенос строки
       
       fs.close(); // закрываем файл
    }
}
 
int main()
{
    string filename = "array_data.txt";
    const int size = 100;
    int* rand_arr = new int[size];

    srand(time(nullptr)); // используем текущее время, чтобы сгенерировать рандомные значения
    int lef_border = 5;
    int range_len = 10; // правая граница = range_len + left_border
    for (int i = 0; i < size; i++)
        rand_arr[i] = lef_border + rand() % range_len; // генерируем число в указанном диапазоне и записываем в массив

    write_arr(filename, rand_arr, size); // записываем массив в файл

    int* array_from_file = nullptr;
    int n = 0;
    read_arr(filename, array_from_file, n); // читаем массив из файла

    delete[] rand_arr;
    delete[] array_from_file;
    return 0;
}
