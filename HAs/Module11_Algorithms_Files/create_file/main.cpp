#include <fstream>
#include <random>

int main()
{

    // Create a file stream and open a file
    std::ofstream outfile("large_file.txt");

    // Seed a random number generator
    srand(time(nullptr));
    int left_border = 5;
    int range_len = 1000; // правая граница = range_len + left_border
    
    // Generate 2 Gb of data by writing 2 billion lines to the file
    for (int i = 0; i < 2'000'000'000/sizeof(int); i++)
    {
        outfile << left_border + rand() % range_len << '\n';
    }

    // Close the file
    outfile.close();

    return 0;
}