#include <iostream>
using namespace std;

template <class T1, class T2>
float func(T1 a, T2 b)
{
    float avg = (a + b) / 2.0;
    return avg;
}

float func(int a, double b)
{
    cout << "Exact function will get more priority" << endl;
    float avg = (a + b) / 2.0;
    return avg;
}

int main()
{
    cout << func(1, 4) << endl;
    cout << func(2.3, 5) << endl;
    cout << func(4, 5.7) << endl;
    cout << endl;
    cout << func(1, 4) << endl
         << func(2.3, 5) << endl
         << func(4, 5.7) << endl;
    cout << "Why in 2nd way to call the same arguments show different output?" << endl;
}