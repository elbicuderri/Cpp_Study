#include <iostream>
#include <vector>

void print_value(int value)
{
    std::cout << "Value: " << value << std::endl;
}

void for_each(const std::vector<int>& values, void(*func)(int))
{
    for (int value: values)
        func(value);
}


int main()
{
    std::vector<int> v1 = {1, 5, 4, 2, 3};

    for_each(v1, print_value);

    std::cout << "\n";

    for_each(v1, [](int value){std::cout << "Value: " << value << std::endl;}); // lambda

    return 0;
}