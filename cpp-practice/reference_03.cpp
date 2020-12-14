#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void Swap(int& num1, int& num2)
{
    int tmp;
    tmp = num1;
    num1 = num2;
    num2 = tmp;
}

void BubbleSort(int* (&arr), int len)
{
    int cnt = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = 1; j < len-i; j++) {
            if (arr[j] > arr[j-1]) {
                cout << arr[j] << ", " << arr[j-1] << endl;
                Swap(arr[j], arr[j-1]);
                cnt++;
                cout << cnt << "th Swapped!" << endl;
            }
        }
    }
}

int Solution(string& str)
{
    int len = (int)str.length();
    
    cout << "The length is : " << len << endl;

    int* arr = new int[len];

    for (int i = 0; i < len; i++) {
        cout << "str's " << i << "th : " << str[i] << endl;
        arr[i] = str[i] - '0';
        //cout << "str's " << i << "th : " << str[i] << endl;
        cout << "arr's " << i << "th : " << arr[i] << endl;
    }

    BubbleSort(arr, len);

    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }

    delete []arr;
}

int main()
{
    string str;

    cout << "Enter the number : ";
    cin >> str;

    Solution(str);

    return 0;
}