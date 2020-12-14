#include <iostream>
using namespace std;

class CCircle 
{
private :
    double Radius;
    const double PI;

public :
    CCircle(double r = 0) : Radius(r), PI(3.14) {} // const 변수 PI 초기화
    void SetRadius(double r) { Radius = r; }
    double GetArea() const { return (PI * Radius * Radius); } // const 함수
};

int main()
{
    CCircle Cir1(1);
    cout << "Area : " << Cir1.GetArea() << endl;

    return 0;
}