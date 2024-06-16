// Operator overloading

#include <bits./stdc++.h>
using namespace std;

class Complex
{
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    Complex operator+(Complex const &obj)
    {
        Complex res;
        res.imag = imag + obj.imag;
        res.real = real + obj.real;
        return res;
    }
    void display()
    {
        cout << real << " + i" << imag << endl;
    }
};

int main()
{
    Complex c1(12, 7), c2(7, 5), c4;
    Complex c3 = c1 + c2;
    Complex c5 = c4 + c2;
    c3.display();
    c5.display();
    return 0;
}
