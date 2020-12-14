	// std::ifstream fin(s, std::ios::binary);

	// if (!fin) 
	// {
	// 	std::cout << "Error, cannot find the file." << std::endl;
	// 	return EXIT_FAILURE;
	// }

	// fin.seekg(0, std::ios::end);
	// const size_t number = fin.tellg() / sizeof(float);
	// fin.seekg(0, std::ios::beg);

	// std::vector<float> data(number);
	// fin.read(reinterpret_cast<char*>(&data[0]), number * sizeof(float));

    // std::vector<float> data;

    //float f;
	//std::string s("mean_pytorch.bin");
	//
	//std::ifstream fin(s, std::ios::binary);

	//while (fin.read(reinterpret_cast<char*>(&f), sizeof(float)))
	//	std::cout << f << std::endl;