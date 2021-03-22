#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> vec1;

    std::vector<std::vector<int>> vec2;

    vec1.emplace_back(2000000000);

    vec2.push_back(2000000000);

    return 0;
}