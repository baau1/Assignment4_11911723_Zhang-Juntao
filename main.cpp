#include <iostream>
#include "matrix.h"
using namespace std;
int main()
{
////Test1
    Matrix a;Matrix b(2,2);
    auto **data = new float* [2];
    for (int i = 0; i < 2; i++)
    {
        data[i] = new float[2];
        for (int j = 0; j < 2; j++)
        {
            data[i][j] = i+j+2;
        }
    }
    Matrix c(2,2,data);
    Matrix d(c);
    cout<<a;cout<<b;cout<<c;cout<<d;
    ~c;~d;

////Test2
//    Matrix a;
//    cout<<a;
//    Matrix b(2,2);
//    a=b;
//    cout<<a;
//    ~a;
//    ~b;

////Test3
//    Matrix b(4,4);
//    cout<<b;

////Test4
//    Matrix a;
//    Matrix b;
//    Matrix c;
//    c=(a+b);
//    c=(a*b);
//    cout<<c;

////Test5
//    Matrix a;
//    float b=2.0f;
//    Matrix c;
//    c=(a*b);
//    cout<<c;

////Test6
//    Matrix a;
//    float b=2.0f;
//    Matrix c;
//    c=(b*a);
//    cout<<c;

////Test7
//    Matrix a;
//    Matrix b;
//    Matrix c;
//    c=(a+b);
//    cout<<c;

////Test8
//    Matrix a;
//    Matrix b;
//    Matrix c;
//    c=(a-b);
//    cout<<c;

////Test9
//    Matrix a;
//    float b=2.0f;
//    Matrix c;
//    c=(a/b);
//    cout<<c;

////Test10
//    Matrix a;
//    Matrix b;
//    Matrix c;
//    c=(a+b);
//    a==b;
//    a==c;
    return 0;
}
