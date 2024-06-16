#include <iostream>
using namespace std;

class Base1
{
public:
    void greet()
    {
        cout << "How are you?" << endl;
    }
};

class Base2
{
public:
    void greet()
    {
        cout << "Kaise ho?" << endl;
    }
};

class Derived : public Base1, public Base2
{
    int a;

public:
    void greet()
    {
        Base2 ::greet(); // this ensures that greet of Base2 will call upon
    }
};

class B
{
public:
    void say()
    {
        cout << "Hello world" << endl;
    }
};

class D : public B
{
    int a;
    // D's new say() method will override base class's say() method
public:
    void say()
    {
        cout << "Hello my beautiful people" << endl;
    }
};

class B1 : virtual public B
{
};

class B2 : virtual public B
{
};

class B3 : public B1, public B2
{
public:
    void display()
    {
        say(); // this function is a method function of B class coming to this either from B->B1 or from B->B2
    }
};

int main()
{
    // Ambibuity 1 - if a class derived from 2 base class with a common member function, then upon calling which member function will call upon
    Derived d;
    d.greet();

    // Ambibuity 2 - if derived and base class has same member function, then which will execute on calling
    D obj;
    obj.say();

    // Ambiguity 3 - if a function of derived class is called by its  2 derived's derived class
    B3 obj2;
    obj2.display();

    return 0;
}