#include <iostream>
#include <vector>

int main()
{
	std::vector<int> a = { 3, 4, 2 };

	auto b = std::vector<int>(a.begin(), a.end());

	for (int i = 0; i < b.size(); ++i) {
		std::cout << b[i] << std::endl;
	}

	for (auto &e : b) {
		std::cout << e << std::endl;
	}

	return 0;
}
