// Function Overloading

#include <bits./stdc++.h>
using namespace std;

class ApnaCllg
{
public:
    void fun()
    {
        cout << "no argument" << endl;
    }

    void fun(int x)
    {
        cout << "int argument" << endl;
    }

    void fun(double x)
    {
        cout << "double argument" << endl;
    }
};

int main()
{
    ApnaCllg obj;
    obj.fun();
    obj.fun(4);
    obj.fun(6.2);
}