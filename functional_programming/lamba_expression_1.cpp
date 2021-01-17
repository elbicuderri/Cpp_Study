#include <iostream>

class Plus
{
public:
	explicit Plus(int a): Var(a) {}
	int operator() (int x) const
	{
		return Var + x;
	}

private:
	int Var;
};

int main()
{
	auto LambdaPlus3 = [Var = 3](int x)
	{
		return Var + x;
	};

	std::cout << LambdaPlus3(10) << std::endl;

	Plus plus3(3);

	std::cout << plus3(10) << std::endl;

	return 0;
}