#include <iostream>

struct Point
{
    int x;
    int y;
};

int main()
{
    Point P1;
    P1.x = 3;
    P1.y = 4;

    std::cout << P1.x << " " << P1.y << std::endl;

    return 0;
}