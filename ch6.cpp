#include <iostream>
#include <memory>

struct AllocationMetrics
{
	size_t TotalAllocated = 0;
	size_t TotalFreed = 0;

	size_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size)
{

	s_AllocationMetrics.TotalAllocated += size;

	return malloc(size);

}

void operator delete(void* memory, size_t size)
{

	s_AllocationMetrics.TotalFreed += size;

	free(memory);
}

static void PrintMemoryUsage()
{
	std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage()
		<< " byte" << std::endl;
}

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
	PrintMemoryUsage();

	{
		E* e1 = new E();
		PrintMemoryUsage();

		std::unique_ptr<E> e2{ new E() };
		PrintMemoryUsage();

		std::unique_ptr<E> e3(new E());
		PrintMemoryUsage();

		std::unique_ptr<E> e4 = std::make_unique<E>();
		PrintMemoryUsage();

		std::shared_ptr<E> e5 = std::make_shared<E>();
		PrintMemoryUsage();

		std::shared_ptr<E> e6 = e5;
		PrintMemoryUsage();

		std::weak_ptr<E> e7 = e6;
		PrintMemoryUsage();

	}
	PrintMemoryUsage();

	return 0;
}