#include <iostream>
using namespace std;

class CCircle 
{
private:
    class CPoint {
        private:
            int x;
            int y;

        public:
            CPoint(int a = 0, int b = 0) : x(a), y(b) { cout << "x : " << x << ", y : " << y << endl; }
            void Move(int a, int b) { x += a; y += b; }
            void Print() { cout << "Center: (" << x << ", " << y << ")" << endl; }
    };

    CPoint Center;
    double Radius;

public:
    CCircle(int a, int b, double r) : Radius(r) { Center.Move(a, b); }
    void Print() {
        Center.Print();  // using object's Center
        cout << "radius : " << Radius << endl;
    }
};

int main()
{
    CCircle cir(3, 4, 5);
    cir.Print();

    return 0;
}
