#include <iostream>
using namespace std;
#define PI 3.14

class CCircle 
{
protected :
    int x, y; // 중심
    double Radius; // 반지름

public :
    CCircle(int a, int b, double r) : x(a), y(b), Radius(r) {
        cout << "CCircle Constructor" << endl; }
    ~CCircle() { cout << "CCircle Destructor" << endl; }
    double GetArea() { return (PI * Radius * Radius); }

};

class CSphere : public CCircle 
{
private :
    int z;

public :
    CSphere(int a, int b, int c, double r) : CCircle(a, b, r), z(c) {
        cout << "CSphere Constructor" << endl; }
    ~CSphere() { 
        cout << "CSphere Destructor" << endl; }
    double GetArea() { return (4 * PI * Radius * Radius); } // function overriding
    double GetVolume() { return ((4.0/3.0) * PI * Radius * Radius * Radius); }

};

int main()
{
    CSphere Sph(1, 1, 1, 1);
    cout << Sph.GetArea() << endl;
    cout << Sph.GetVolume() << endl;

    return 0;
}