#include <iostream>
#include <vector>

int main()
{
	std::vector<float> a{ 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };

	const void* b = (const void*)&a[0];

	std::vector<float> c1(5);
	for (int i = 0; i < 5; ++i) {
		c1[i] = ((float*)b)[i];
	}

	for (auto &e : c1) {
		std::cout << e << std::endl;
	}

	std::vector<float> c2;
	c2.insert(c2.end(), &((float*)b)[0], &((float*)b)[5]);

	for (auto &e : c2) {
		std::cout << e << std::endl;
	}

	std::vector<float> c3;
	c3.resize(5);
	std::memcpy(&c3[0], (float*)b, 5 * sizeof(float));

	for (auto &e : c3) {
		std::cout << e << std::endl;
	}
	return 0;
}
