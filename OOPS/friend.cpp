/* friend functions can access private methods and members of class
but are not in the scope of class and so can't be called from the obj of that class */

#include <iostream>
using namespace std;

// Forward declaration is necessary if we call something earlier but we declared it later in our program
class Complex;

class Calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }

    int sumRealComplex(Complex, Complex);
    int sumCompComplex(Complex, Complex);
};

class Complex
{
    int a, b;
    // Individually declaring functions as friends
    // friend int Calculator ::sumRealComplex(Complex, Complex);
    // friend int Calculator ::sumCompComplex(Complex, Complex);

    // Aliter: Declaring the entire calculator class as friend
    friend class Calculator;

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }

    friend int check(Complex c1, Complex c2); // Complex class bolega friend hai mera check function jiska data type int hai
    friend Complex sumComplex(Complex c1, Complex c2);
};

int Calculator ::sumRealComplex(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

int Calculator ::sumCompComplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

int check(Complex c1, Complex c2)
{
    if (c1.a == c2.a && c1.b == c2.b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Complex sumComplex(Complex c1, Complex c2)
{
    Complex c3;
    c3.setNumber((c1.a + c2.a), (c1.b + c2.b)); // we can access members and functions of class Complex, even private
    return c3;
}

int main()
{
    Complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(1, 4);
    Calculator calc;
    int res = calc.sumRealComplex(o1, o2);
    cout << "The sum of real part of o1 and o2 is " << res << endl;
    int resc = calc.sumCompComplex(o1, o2);
    cout << "The sum of complex part of o1 and o2 is " << resc << endl;

    if (check(o1, o2))
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "different" << endl;
    }

    Complex sum;
    sum = sumComplex(o1, o2);
    sum.printNumber();

    // o1.sumComplex()  we can't write this, as sumComplex() not become a member function of class

    return 0;
}