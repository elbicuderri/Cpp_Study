#include <iostream>

void hello()
{
    std::cout << "Hello!" << std::endl;
}

int main()
{

    auto func1 = hello;
    // auto& func1 = hello;

    func1();

    void(*func2)() = hello;

    func2();

    typedef void(*hellofunc)();

    hellofunc func3 = hello;

    func3();

    return 0;
}