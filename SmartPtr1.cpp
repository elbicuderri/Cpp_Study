#include <iostream>
#include <memory>

class E
{
public:

	E() // constructor
	{
		std::cout << "Hello~" << std::endl;
	}

	~E() // destructor
	{
		std::cout << "Bye~" << std::endl;
	}

};

int main()
{

	E* e1 = new E();

	std::unique_ptr<E> e2{ new E() };
	std::unique_ptr<E> e3(new E());
	std::unique_ptr<E> e4 = std::make_unique<E>();

	std::shared_ptr<E> e5 = std::make_shared<E>();

	std::shared_ptr<E> e6 = e5;

	std::weak_ptr<E> e7 = e6;

	return 0;
}
