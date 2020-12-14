#include <iostream>
using namespace std;
#define PI 3.14

class CCircle 
{
protected : // 멤버 변수를 protected으로 선언
    int x, y; // 중심
    double Radius; // 반지름

public :
    double GetArea() { return (PI * Radius * Radius); }

};

class CSphere : public CCircle 
{
private :
    int z;

public :
    CSphere(int a, int b, int c, double r) { x = a; y = b; z = c; Radius = r; } 
    double GetVolume() { return ((4.0/3.0) * PI * Radius * Radius * Radius); }

};

int main()
{
    CSphere sph(1, 2, 3, 4);
    cout << sph.GetVolume() << endl;

    return 0;
}