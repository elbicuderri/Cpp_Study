#include <iostream>
#include <memory>

//void up(int value)
//{
//	value++;
//}
//
//void up(int* value)
//{
//	(*value)++;
//}

void up(int& value)
{
	value++;
}

int main()
{
	int a = 1;

	up(a);

	std::cout << a << std::endl;
	
	return 0;
}
