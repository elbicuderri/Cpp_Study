#include <iostream>
#include <vector>
#include <numeric>

double average_score(const std::vector<int>& scores)
{
	return std::accumulate(scores.begin(), scores.end(), 0) / (double)scores.size();
}

int main()
{
	std::vector<int> ss{ 3, 4, 5, 6, 7, 9 };

	auto answer = average_score(ss);

	std::cout << answer << std::endl;

	return 0;
}