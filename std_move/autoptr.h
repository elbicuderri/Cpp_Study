#include <iostream>

template<typename T>
class AutoPtr
{
// private:
public:
    T* m_ptr;

public:
    AutoPtr(T* ptr = nullptr)
    : m_ptr(ptr)
    {
        std::cout << "AutoPtr default constructor~" << std::endl;
    }

    ~AutoPtr()
    {
        std::cout << "AutoPtr destructor~" << std::endl;
    }

    AutoPtr(const AutoPtr& a)
    : m_ptr(ptr)
    {
        std::cout << "AutoPtr copy constructor~" << std::endl;
        
        //deep copy
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }

    AutoPtr& operator=(const AutoPtr& a)
    {
        std::cout << "AutoPtr copy assignment" << std::endl;

        if (&a == this)

        if (m_ptr != nullptr)

        //deep copy
        //...
    }



};