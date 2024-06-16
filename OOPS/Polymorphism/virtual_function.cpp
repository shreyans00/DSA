#include <bits./stdc++.h>
using namespace std;

// abstract class is a class in which there is atleast one pure virtual function
class base
{
public:
    virtual void print()
    {
        cout << "virtural base print" << endl;
    }

    void display()
    {
        cout << "not virtual base display" << endl;
    }

    virtual void show() = 0; // do nothing function -> pure virtual function
};

class derived : public base
{
public:
    void print()
    {
        cout << "derived print" << endl;
    }

    void display()
    {
        cout << "derived display" << endl;
    }

    void show()
    {
        cout << "this function is neccessary to be made in derived class since its base class function is pure virtual" << endl;
    }
};

int main()
{
    base *baseptr;
    derived d;
    baseptr = &d;       // we stored address of derived class in a pointer of base class
    baseptr->print();   // we make this method function virtual
    baseptr->display(); // we won't make this method function virtual, so it displays base class function by default
    cout << endl;
    derived r;
    r.print();
    r.display();
    r.show();
    return 0;
}