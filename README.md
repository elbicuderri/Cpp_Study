# Cpp_study

## Cpp keyword 정리(내가 이해한 바대로.. 쓴 것이다)

- explicit : type 변환을 막기 위해(컴파일러가 저절로 하는 것을) 주로 constructor에 쓴다.
- class 멤버 함수 뒤의 const : 이 멤버 함수 안에서 어떤 변수도 바꿀 수 없다는 의미.
- virtual : 상속하는 class에서 이 멤버 함수를 override하라는 명령이라고 생각하면 됨. 이 멤버 함수를 쓰세요!
- constexpr : const는 run-time에 오류 발생. constexpr는 compile-time에 오류 발생. 함수 및 클래스에도 사용 가능.
<br>
<br>

## using vs typedef

[using vs typedef](https://unikys.tistory.com/381)

#### Tips for Cpp

[Cpp PDF](https://mirror.adversec.com/dprk/dprk-34c4/DPRK-34C3-PDFs/ProgramingBooks/02_cppprogramming.pdf)

```cpp
//reference
#include <iostream>
#include <memory>

void up_v(int value) // it do not work
{
	value++;
}

void up_p(int* value) // c style 
{
	(*value)++;
}

void up_r(int& value) // cpp style ( c do not support this )
{
	value++;
}

int main()
{
	int a = 1;

	up_r(a);

	std::cout << a << std::endl;
	
	return 0;
}
```


```cpp
// constructor && destructor && unique_ptr
#include <iostream>
#include <memory>
#include <string>

class Name
{	
public:
	Name(std::string i) : ID(i) { std::cout << "hello " << ID << std::endl; }

	~Name () { std::cout << "bye " << ID << std::endl; }

private:
	std::string ID;

};

int main()
{
  Name* a = new Name("John");

  Name b("Charon");

  std::unique_ptr<Name> c{ new Name("Eddy") };

  std::unique_ptr<Name> d = std::make_unique<Name>("TT");

  Name* e = new Name("Henry");

  std::unique_ptr<Name> f(e);

  // f.reset(a);

	return 0;
}
```


```cpp
//cpp code for reading binary file
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>

template<typename T> // T is type
std::vector<T> ReadData(const std::string& fname)
{
    std::ifstream input(fname, std::ios::in | std::ios::binary);
    if (!(input.is_open()))
    {
        std::cout << "Cannot open the file!!!" << std::endl;
        std::exit(-1);
    }

    std::vector<T> data;
    input.seekg(0, std::ios::end);
    auto size = input.tellg();
    input.seekg(0, std::ios::beg);

    for (int i = 0; i < size / sizeof(T); ++i)
    {
        T value;
        input.read((char*)&value, sizeof(T));
        data.emplace_back(value);
    }

    return data;
}

int main(int argc, char** argv)
{
    const std::string path = argv[1];

    auto unknown_data = ReadData<char>(path); 

    for (auto &e : unknown_data) 
    {
        std::cout << e;
    }

    std::cout << "\n";

    return 0;
}
```


```cpp
//vector slicing
int main()
{
	std::vector<int> a = { 1,23,4,5,6,7,8,2,3,4,5,7,98,1 };

	auto b = std::vector<int>(a.begin(), a.begin() + 3);

	auto c = std::vector<int>(a.begin() + 3, a.begin() + 5);

	auto d = std::vector<int>(a.begin() + 5, a.end() - 1);

	for (auto &e : d) 
	{
		std::cout << e << std::endl;
	}

	return 0;
}
```


```cpp
//Three ways to convert void array to float vector
int main()
{
	std::vector<float> a{ 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };

	const void* b = (const void*)&a[0];

	std::vector<float> c1(5);
	for (int i = 0; i < 5; ++i) 
	{
		c1[i] = ((float*)b)[i];
	}

	std::vector<float> c2;
	c2.insert(c2.end(), &((float*)b)[0], &((float*)b)[5]);

	std::vector<float> c3;
	c3.resize(5);
	memcpy(&c3[0], (float*)b, 5 * sizeof(float));

	return 0;
}
```


```cpp
//about char array
int main()
{
	__int8* a = new __int8[5];

	for (int i = 0; i < 5; ++i) 
	{
		a[i] = i + 1;
	}

	void* va = (void*)a;

	char* b = (char*)va;

	for (int j = 0; j < 5; ++j) 
	{
		if (b[j] % 2 == 0) 
		{
			std::cout << "even" << std::endl;
		}
		else
		{
			std::cout << "odd" << std::endl;
		}
	}

	return 0;
}
```


```cpp
//start using template
template<typename T>
T add(T& x, T& y)
{
	T answer = x+y;

	return answer;
}

int main()
{
	int a = 1, b = 2;

	auto c = add(a, b);

	float f = 3.0f, g = 4.0f;

	auto h = add(f, g);

	std::cout << "c: " << c << std::endl;
	std::cout << "h: " << h << std::endl;

	return 0;
}
```


**내가 auto를 쓰는 경우**
>
> 1. 오른쪽 항에서 너무 너무 너무 확실히 type이 보일때 그리고 너무 길때
>
> 2. vector for문 돌릴 때
>
> 3. ~~type을 잘 모를 때 (이거 완전 쓰레기 아니야)~~
>

```cpp
//smart ptr simple example
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
	{
		E* e1 = new E();

		std::unique_ptr<E> e2{ new E() };
		
		std::unique_ptr<E> e3(new E());
		
		std::unique_ptr<E> e4 = std::make_unique<E>();

		std::shared_ptr<E> e5 = std::make_shared<E>();

		std::shared_ptr<E> e6 = e5;

		std::weak_ptr<E> e7 = e6;
	{
	
	return 0;
}
```
