#include <iostream>

using namespace std;

struct Point 
{
private:
    int x;
    int y;

public:
    void SetXY(int a, int b) { x=a; y=b;}
    void Print() { cout << "(" << x << ", " << y << ")" << endl; }
};

int main()
{
    Point P1;
    P1.SetXY(3, 4);
    P1.Print();

    return 0;
}