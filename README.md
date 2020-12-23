# Cpp_study

#### Tips for Cpp


# The way to read the serial number of the nano in the docker container

```docker
$ docker run -itd --gpus all --name ${container name} -v /sys:/root/sys $[image name or ID}

$ cat /root/sys/firmware/devicetree/base/serial-number
```

```cpp
//cpp code
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

template<typename T>
std::vector<T> ReadData(const std::string& fname)
{
    std::ifstream input(fname, std::ios::in | std::ios::binary);
    if (!(input.is_open()))
    {
        std::cout << "Cannot open the file!!!" << std::endl;
        std::exit(-1);
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
    const std::string path = "/root/sys/firmware/devicetree/base/serial-number";

    auto unknown_data = ReadData<char>(path);

    for (auto &e : unknown_data) 
    {
        std::cout << e;
    }

    std::cout << "\n";

    return 0;
}
```
