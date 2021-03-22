#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> a;

    cout << "capacity: " << (int)a.capacity() << endl;

    a.reserve(100); // this is important
    cout << "capacity: " << (int)a.capacity() << endl;

    vector<int> a1 = {1, 2, 3, 4};
    vector<int> a2 = {5, 6, 7, 8};
    vector<int> a3 = {3, 4, 5, 2};
    vector<int> a4 = {0, 1, 9, 3};

    // a.push_back(a1);
    // a.push_back(a2);
    // a.push_back(a3);
    // a.push_back(a4);

    a.push_back(vector<int>{1, 2, 3, 4});
    cout << "capacity: " << (int)a.capacity() << endl;
    a.push_back(vector<int>{5, 6, 7, 8});
    cout << "capacity: " << (int)a.capacity() << endl;
    a.push_back(vector<int>{3, 4, 5, 2});
    cout << "capacity: " << (int)a.capacity() << endl;
    a.push_back(vector<int>{0, 1, 9, 3});
    cout << "capacity: " << (int)a.capacity() << endl;
    // What is difference??

    cout << endl;

    cout << "pointer of a: " << (int)a.data() << endl;
    // cout << "pointer of a: " << (int)&a << endl; //// ??
    cout << "pointer of a[0]: " << (int)&a[0] << endl;
    cout << "pointer of a[1]: " << (int)&a[1] << endl;
    cout << "pointer of a[2]: " << (int)&a[2] << endl;
    cout << "pointer of a[3]: " << (int)&a[3] << endl;

    cout << endl;

    // cout << (int)&a1[0] << endl;
    // cout << (int)&a2[0] << endl;
    // cout << (int)&a3[0] << endl;
    // cout << (int)&a4[0] << endl;

    // cout << endl;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << (int)&a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}