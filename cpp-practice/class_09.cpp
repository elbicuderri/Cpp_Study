#include <iostream>
using namespace std;

struct Cpoint 
{
    int x, y;
};

void Move(Cpoint* This, int a, int b)
{
    This->x += a;
    This->y += b;
}

void Print(Cpoint* This)
{
    cout << "(" << This->x << ", " << This->y << ")" << endl;
}

int main()
{
    Cpoint P1 = {1, 2};
    Cpoint P2 = {3, 4};

    Move(&P1, 1, 1);
    Move(&P2, 2, 2);

    Print(&P1);
    Print(&P2);

    return 0;
}