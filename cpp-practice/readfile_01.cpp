#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>

void load_data(float* arr, std::string file_name);

int main()
{
	std::string s("mean_pytorch.bin");

    float* arr;

    load_data(arr, s);

	std::cout << "=====================================================" << std::endl;

	// size_t length = 5;

	for (size_t i = 0; i < 5; ++i) 
	{
		std::cout << arr[i] << std::endl;
	}

	return 0;
}

void load_data(float* arr, std::string file_name)
{
    std::ifstream input(file_name, std::ios::binary);
    if (!input)
    {
		std::cout << "Error, cannot find the file." << std::endl;
		exit(-1);     
    }

    input.seekg(0, std::ios::end);
	const size_t number = input.tellg() / sizeof(float);
	input.seekg(0, std::ios::beg);

    std::vector<float> data(number);
    input.read(reinterpret_cast<char*>(&data[0]), number * sizeof(float));

	if (data.size() == 0)
	{
		std::cout << "Read Error!" << std::endl;
		exit(-1);
	}
	else { std::cout << "The size is : " << data.size() << std::endl; }

    for (size_t i = 0; i < data.size(); ++i) 
	{
		std::cout << std::fixed << std::setprecision(10) << data[i] << std::endl;
	}

	std::cout << "=====================================================" << std::endl;

    arr = data.data();

    for (size_t i = 0; i < data.size(); ++i) 
	{
		std::cout << arr[i] << std::endl;
	}

}