#include <iostream>

using namespace std;

class CArray
{
private:
    int count;
    int* x;

public:
    CArray(int a) { count = a; x = new int[count]; }
    void Delete() { delete [] x;}
    void Print() {
        for (int i = 0; i < count; i++){
            cout << x[i] << endl;
        }
    }
};

int main()
{
    CArray ary(5);
    ary.Print();
    ary.Delete();

    return 0;
}