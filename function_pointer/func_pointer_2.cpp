#include <iostream>

void hello(int a)
{
    std::cout << "Hello Value! " << a << std::endl;
}

int main()
{

    auto func1 = hello;
    // auto& func1 = hello;

    func1(3);

    void(*func2)(int) = hello;

    func2(3);

    typedef void(*hellofunc)(int);

    hellofunc func3 = hello;

    func3(5);

    return 0;
}