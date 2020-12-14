#include <iostream>
using namespace std;

class CPoint 
{
private :
    int x, y;
    static int count; // static 멤버 변수
    
public :
    CPoint(int a = 0, int b = 0) : x(a), y(b) { count++; }
    ~CPoint() { count--; }
    void Print() { cout << "(" << x << ", " << y << ")" << endl; }
    static int GetCount() { return count; } // static 멤버 함수
};

int CPoint::count = 0; // 초기값이 없을 경우 0으로 초기화

int main()
{
    CPoint P1(1, 2);
    CPoint *P2 = new CPoint(3, 4);

    cout << "count : " << CPoint::GetCount() << endl;
    // static 함수 호출
    delete P2;
    cout << "count : " << P1.GetCount() << endl;

    return 0;
}