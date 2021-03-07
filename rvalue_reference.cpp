#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Test
{
private:
    int m_Int;

public:
    Test() : m_Int(0) {}

    Test(const int& val) : m_Int(val) { cout << "Lvalue!!" << endl; }

    Test(int&& val) : m_Int(move(val)) { cout << "Rvalue!!" << endl; }

    ~Test() {}

    void Print() const { cout << m_Int << endl; }

};

int main()
{
    int a = 1;
    int& b = a;

    string c = "Hi";

    Test x(a);
    Test y(b);
    Test z(1);

    vector<string> v;

    v.push_back(c);

    cout << c << endl;

    v.push_back(move(c)); // this is important

    cout << c << endl;

    cout << v[0] << ", " << v[1] << endl;

    return 0;
}