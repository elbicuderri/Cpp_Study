#include <iostream>
#include <vector>

int main()
{
	std::vector<int> a = { 1,23,4,5,6,7,8,2,3,4,5,7,98,1 };

	auto b = std::vector<int>(a.begin(), a.begin() + 3);

	auto c = std::vector<int>(a.begin() + 3, a.begin() + 5);

	auto d = std::vector<int>(a.begin() + 5, a.end() - 1);

	for (auto &e : d) {
		std::cout << e << std::endl;
	}

	return 0;
}
