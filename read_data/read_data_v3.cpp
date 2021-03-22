#include <iostream>
#include <vector>
#include <string>
#include <fstream>

template<typename T>
std::vector<T> ReadData(const std::string& file_name)
{
    std::ifstream input(file_name, std::ios::in | std::ios::binary);
    if (!(input.is_open()))
    {
        std::cout << "Cannot open the file!!!" << std::endl;
        exit(-1);
    }

    std::vector<T> data;
    input.seekg(0, std::ios::end);
    auto size = input.tellg();
    input.seekg(0, std::ios::beg);

    for (int i = 0; i < size / sizeof(T); ++i)
    {
        T value;
        input.read((char*)&value, sizeof(T));
        data.emplace_back(value);
    }

    return data;
}

int main(int argc, char** argv)
{
    const std::string& file = argv[1];

    // const std::string file = "/lib/firmware/tegra21x/acr_ucode.bin";
    // /lib/firmware/tegra21x/ any file

    std::vector<int> unknown_data = ReadData<int>(file);

    for (auto &e : unknown_data) 
    {
        // char asciiChar = char(e);
        std::cout << char(e) << std::endl;
    }

    // for (auto &e : unknown_data) 
    // {
    //     std::cout << static_cast<char>(e) << std::endl;
    // }

    return 0;
}