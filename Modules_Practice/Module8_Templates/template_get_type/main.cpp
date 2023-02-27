#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T> void print_type_name(T x) {
    cout << typeid(x).name() << endl;
}

auto main() -> int 
{

    auto a = 42;
    const auto* pa = &a;
    auto b = true;
    auto c = 'A';
    auto s = "строка";
    auto f = 5.2;
    auto sum = 2L + 4U;

    print_type_name(a);
    print_type_name(b);
    print_type_name(c);
    print_type_name<string>(s);
    print_type_name(f);
    print_type_name(pa);
    print_type_name(sum);

    return 0;
}