#include <iostream>
using namespace std;

int count = 1;
class student
{
    string name; // private data member

public:
    int age;
    bool gender;

    void printInfo()
    {
        cout << "Name= ";
        cout << name << endl;
        cout << "Age= ";
        cout << age << endl;
        cout << "Gender= ";
        cout << gender << endl;
    }

    void getName()
    {
        cout << name << endl;
    }

    /*Construction is a special member function with the same name as that of the class used to initialise objects of class.
    It should be declared in public section and get automatically invoked when object is created. 
    It doesn't have any return types.
    We can't refer to their addresses. */

    student(string s, int a, int g) //parameterised constructor
    // student(string s, int a, int g) : name(s), age(a), gender(g)    // can be called by initialising list method as well
    // student(string s, int a, int g) : name(s), age(gender - a), gender(g) // gender will give garbage value (Red Flag) here since age will be initialised first
    {
        name = s;
        age = a;
        gender = g;
    }

    student(string s)
    {
        name = s;
    }

    student() //here we are not passing any parameter, so it's a Default constructor
    {
        cout << "Default constructor" << endl;
    }

    // When no copy constructor is found, compiler supplies its own copy constructor.
    student(student &a) // Copy constructor
    {
        name = a.name;
        age = a.age;
        gender = a.gender;
        cout << "copy constructor invoked" << endl;
    }

    // Destructor neither takes arguments nor returns any value
    ~student() // Destructor called when program ends
    {
        cout << "Destructor called for " << count++ << " times" << endl;
    }

    // Operator Overloading - We can overload operators( == , + , - ,etc), to work on class objects.
    bool operator==(student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    student a("Urvi", 20, 1);
    a.printInfo();
    cout << "\nBlock is executing" << endl;
    {
        student b("Aman");
        b.getName();
        cout << endl;
        student c;
        cout << endl;
    }
    cout << "Block ends and so destructors are called for inside ones, since its scope has end\n"
         << endl;
    student d = a; //student d(a);   copy constructor invoked
    d.printInfo();
    // student e;
    // e = a;              copy constructor not invoked
    // e.printInfo();
    cout << endl;

    // Shallow Copy - The object and its copy, point to the same memory address.
    // If you make a change in its copy it gets changed in the main copy as well and vice versa.

    // Deep Copy - The object and its copy, point to different addresses in the memory.
    // If you make a change in its copy it will not get changed in the main copy and vice versa

    if (d == a)
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "Not same" << endl;
    }
    cout << endl;

    return 0;
}