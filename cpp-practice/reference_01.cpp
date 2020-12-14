#include <iostream>
using namespace std;

//C style
void swap(int* num1, int* num2)
{
    int tmp;
    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int main()
{
    int arr[2] = {10, 20};

    swap(&arr[0], &arr[1]);

    cout << "swap(int*, int*) : " << arr[0] << " " << arr[1] << endl;

    return 0;
}