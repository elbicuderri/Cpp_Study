#include <iostream>
using namespace std;

class cpoint
{
private:
    int x, y;

public:
    void setXY(int a, int b) { x = a; y = b; }
    void Print() { cout << "(" << x << ", " << y << ")" << endl; }
};

int main()
{
    cpoint pt[5];
    int i;

    for (i = 0; i < 5; i++)
        pt[i].setXY(i, i);
        // pt[i].Print();

    for (i = 0; i < 5; i++)
        pt[i].Print();

    return 0;
}