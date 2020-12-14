#include <iostream>
#include <fstream>

void load_data(float* output, const char* name, int size)
{
	FILE *pFile = fopen(name, "rb");

	if (pFile == nullptr) 
    {
		printf("cannot find file\n");
		exit(-1);
	}

	size_t sizet = fread(output, size * sizeof(float), 1, pFile);

	if (sizet != 1) 
    {
		printf("read error!\n");
		exit(-1);
	}

	fclose(pFile);
}

void load_data_cpp(float* output, const char* name, int size) 
{	
  std::ifstream pfile(name, std::ios::binary);
  pfile.read((char*)output, size * sizeof(float));
}

int main()
{
    const int K = 5;
	float* mean = new float[K];
	load_data(mean, "mean_pytorch.bin", K);

    for (int i = 0; i < K; i++)
    {
        std::cout << mean[i] << std::endl;
    }

	std::cout << "=====================================================" << std::endl;

	float* mean_cpp = new float[K];
	load_data_cpp(mean_cpp, "mean_pytorch.bin", K);

    for (int i = 0; i < K; i++)
    {
        std::cout << mean_cpp[i] << std::endl;
    }

    return 0;
}