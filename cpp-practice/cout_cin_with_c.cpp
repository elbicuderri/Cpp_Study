// #include <stdio.h>
#include <cstdio>
using namespace std;

// VC++ 6.0에서는 삭제
    char endl[] = "\n";
    char tab[] = "\t";

class ostream 
{
public :
    ostream &operator<<(int val) {
    // int 값에 대한 출력 연산자(<<) 오버로딩
        printf("%d", val);
        return (*this);
    }

    ostream &operator<<(char str[]) {// char * 값에 대한 << 연산자 오버로딩
        printf("%s", str);
        return (*this);
    }
};

class istream 
{
public :
    istream &operator>>(int &val) {// int 값에 대한 >> 연산자 오버로딩
        scanf("%d", &val);
        return (*this);
    }

    istream &operator>>(char str[]) {// char * 값에 대한 >> 연산자 오버로딩
        scanf("%s", str);
        return (*this);
    }
};

ostream cout;
istream cin;

int main()
{
    int a = 5;
    char str[] = "C++ Programming";
    cout << a << tab << str << endl;
    cout << "Enter : ";
    cin >> a >> str;
    cout << a << tab << str << endl;
    return 0;
}