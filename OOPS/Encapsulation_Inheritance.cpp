// Encapsulation means hiding sensitive data from the user

// Access Modifiers             Own/base/parent class       Derived/child class       Outside the class
// Public                               1                           1                        1
// Protected                            1                           1                        0
// Private                              1                           0                        0

// Inheritance - Single, Multiple, Multi-level, Hybrid, Hierarchical

// To inherit the private data members of a class, we store that data member value to a member function of that class which is public and can access through that

#include <iostream>
using namespace std;

class A
{
public:
    void Afunc() // Member function
    {
        cout << "A\n";
    }

protected:
    void Afunc2()
    {
        cout << "A2\n";
    }
};

class B
{
public:
    void Bfunc()
    {
        cout << "B\n";
    }

private:
    void Bfunc2()
    {
        cout << "B2\n";
    }
};

class C : public A, public B
{
public:
    void Cfunc()
    {
        cout << "C\n";
        Afunc2(); // we can call protected
        // Bfunc2();   we can't call private in derived class
    }
};

class D : public C // Default visibility mode is private
{
public:
    void Dfunc()
    {
        Afunc2();
        Bfunc();
    }
};

int main()
{
    C obj;
    obj.Afunc();
    obj.Bfunc();
    obj.Cfunc();
    // obj.Afunc2();    we can't call protected and private outside class
    // obj.Bfunc2();
    D obj2;
    obj2.Dfunc();
}
