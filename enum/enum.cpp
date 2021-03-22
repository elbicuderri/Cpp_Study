#include <iostream>
#include <typeinfo.h>

enum Color
{
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_WHITE,
    COLOR_BLACK,
};

enum Season
{
    SPRING = 3,
    SUMMER = 6,
    FALL = 9,
    WINTER = 12
};

int main()
{
    Color c1 = COLOR_RED;
    Color c2(COLOR_BLUE);
    Color c3{COLOR_WHITE};

    Season s1 = SPRING;

    // Season s2 = c2;

    std::cout << s1 << std::endl;

    return 0;
}