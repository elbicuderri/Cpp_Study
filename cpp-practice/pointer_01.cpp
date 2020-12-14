#include <iostream>
using namespace std;

int main(void)
{
    int var = 2;
    int &ref1 = var;
    int &ref2 = ref1;

    ref1 = 5;

    cout << "var : " << var << endl;
    cout << "ref1 : " << ref1 << endl;
    cout << "ref2 : " << ref2 << endl;
    
    return 0;
}