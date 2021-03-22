#include <iostream>
#include <tuple>

auto my_func()
{
        return std::tuple(123, 456, "Hi");
}


int main()
{
        auto result = my_func();

        std::cout << std::get<0>(result) << " " << std::get<1>(result) << " " << std::get<2>(result) << std::endl;

        /*
        for (auto& e : result) {
                std::cout << e << std::endl;
        }
        */

        std::apply([](auto&&... args) {((std::cout << args << std::endl), ...);}, result);

        std::cout << "Hello world~" << std::endl;

        return 0;
}