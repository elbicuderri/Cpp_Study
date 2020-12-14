#include <iostream>
using namespace std;

#define PI 3.14

class CCircle 
{
public :
    int x, y; // 중심
    double Radius; // 반지름
    
public :
    double GetArea() { return (PI * Radius * Radius); } // 면적
};

class CSphere : public CCircle // CCircle로부터 상속
{
public :
    int z;

public :
    double GetVolume() { return ((4.0/3.0) * PI * Radius * Radius * Radius); }
};

int main()
{
    CSphere Sph;
    Sph.x = 1; Sph.y = 1; Sph.z = 1; Sph.Radius = 5; // Sph:x, y, Radius 상속
    cout << "구의 표면적 : " << Sph.GetArea() << endl; // Sph:GetArea 상속
    cout << "구의 부피: " << Sph.GetVolume() << endl;

    return 0;
}