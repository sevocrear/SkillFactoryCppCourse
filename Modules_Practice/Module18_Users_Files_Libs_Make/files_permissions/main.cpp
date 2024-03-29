#include <fstream>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

void demo_perms(fs::perms p)
{
    std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
        << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
        << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
        << '\n';
}
int main()
{
    std::ofstream("test.txt"); // create file

    std::cout << "Created file with permissions: ";
    demo_perms(fs::status("test.txt").permissions());

    fs::permissions("test.txt",
        fs::perms::group_write | fs::perms::others_all,
        fs::perm_options::remove);

    std::cout << "After removing g-w and o-r:  ";
    demo_perms(fs::status("test.txt").permissions());

    fs::remove("test.txt");
}