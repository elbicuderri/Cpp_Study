#include <iostream>

#include "Vector.h"

template<typename T>
void PrintVector(const Vector<T>& vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
        std::cout << vector[i] << std::endl;

    std::cout << "-----------------------------\n";
}

int main()
{
    Vector<std::string> v1;
    v1.PushBack("seunghwan");
    v1.PushBack("C++");
    v1.PushBack("Vector");
 
    PrintVector(v1);

    return 0;
}