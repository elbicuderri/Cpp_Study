#include <iostream>
using namespace std;

class CPoint 
{
private :
    int x, y;
    CPoint(int a, int b) : x(a), y(b) { }
    ~CPoint() { if (OnlyPoint != nullptr) delete OnlyPoint; }
    static CPoint* OnlyPoint; // 유일한 CPoint 객체를 가리킬 포인터

public :
    static CPoint* GetPoint() // OnlyPoint를 반환하는 함수
    {
        if (OnlyPoint == nullptr) // 최초 수행 시 객체 생성
            OnlyPoint = new CPoint(3, 4);
        return OnlyPoint;
    }

void Print() { cout << "(" << x << ", " << y << ")" << endl; }

};

CPoint *CPoint::OnlyPoint = nullptr; // 초기화, 아직 객체 생성 전

int main()
{
    CPoint::GetPoint()->Print();
    return 0;
}