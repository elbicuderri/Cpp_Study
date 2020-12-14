#include <iostream>
using namespace std;
#define PI 3.14

class CCircle 
{
protected : 
    int x, y; // 중심
    double Radius; // 반지름

public :
    CCircle(int a, int b, double r) : x(a), y(b), Radius(r) {}
    double GetArea() { return (PI * Radius * Radius); }

};

class CSphere : public CCircle 
{
private :
    int z;

public :
    CSphere(int a, int b, int c, double r) : CCircle(a, b, r), z(c) {}
    double GetVolume() { return ((4.0/3.0) * PI * Radius * Radius * Radius); }

};

int main(void)
{
    CSphere sph(1, 2, 3, 4);
    cout << sph.GetVolume() << endl;

    return 0;
}