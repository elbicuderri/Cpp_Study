#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> aa(4);

    std::vector<int> a = {1, 2, 3, 4};

    for (int i = 0; i < 4; ++i) {
        aa.emplace_back(a);
    }

    for (int r = 0; r < 4; ++r) {
        for (int w = 0; w < 4; ++w) {
            std::cout << "[" << r << "]" << "[" << w << "]: ";
            printf("%p\n", &aa[r][w]);
            // std::cout << &(aa[r][w]) << std::endl;
        }
    }

    // for (int &e : a) {
    //     std::cout << &e << std::endl;
    // }

    for (auto &f : aa) {
        for (auto &g : f) {
            std::cout << &g << std::endl;
        }
        std::cout << "=============================\n";
    }

    return 0;
}