#include <iostream>
using namespace std;

void swap1(int a, int b)
{
    int c = a;
    a = b;
    b = c;
    cout << a << "  " << b << endl;
}

void swap2(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;
    cout << a << "  " << b << endl;
}

void swap3(int a, int b)
{
    a ^= b;
    b ^= a;
    a ^= b;
    cout << a << "  " << b << endl;
}

int main()
{
    swap1(2, 4);
    swap2(2, 4);
    swap3(2, 4);
}