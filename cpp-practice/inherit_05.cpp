#include <iostream>
using namespace std;

class CPoint1 
{
private :
    int x;

protected :
    int u;

public :
    CPoint1(int a) : x(a) { cout << "CPoint1 생성자" << endl; }
    ~CPoint1() { cout << "CPoint1 소멸자" << endl; }
    void Print() { cout << "CPoint1" << endl; }
};

class CPoint2 : public CPoint1 
{
private :
    int y;

protected :
    int v;

public :
    CPoint2(int a, int b) : CPoint1(a), y(b) { cout << "CPoint2 생성자" << endl; }
    ~CPoint2() { cout << "CPoint2 소멸자" << endl; }
    void Print() { cout << "CPoint2" << endl; }
};

class CPoint3 : public CPoint2 
{
private :
    int z;

protected :
    int w;

public :
    CPoint3(int a, int b, int c) : CPoint2(a, b), z(c) { cout << "CPoint3 생성자" << endl; }
    ~CPoint3() { cout << "CPoint3 소멸자" << endl; }
    void Print() {
        CPoint1::Print(); // CPoint1의 Print 함수 호출
        CPoint2::Print(); // CPoint2의 Print 함수 호출
        cout << "CPoint3" << endl;
    }
};

int main()
{
    CPoint3 P3(1, 2, 3);
    P3.Print();
    
    return 0;
}