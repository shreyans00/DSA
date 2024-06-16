#include <iostream>
using namespace std;

class student // you can also use struct instead of class
{
    // Class properties
    string name; // data member is private by default

public: // without this we can't use these variable outside this class
    int age;
    bool gender;

    void printInfo(); // member function

    // to use string name, without making it public by setting it with other name
    // Setters are public functions used to set private data members in the class
    void setName(string s)
        name = s;

    // Getters are public functions used to get private data members in the class
    void getName()
            cout
        << name << endl;
};

void student::printInfo() // calling method from ouside        :: -> Scope resolution operator
{
    cout << "Name= ";
    cout << name << endl;
    cout << "Age= ";
    cout << age << endl;
    cout << "Gender= ";
    cout << gender << endl;
}

int main()
{
    student arr[1];

    for (int i = 0; i < 1; i++)
    {
        cout << "Name = ";
        // cin >> arr[i].name;
        string s;
        cin >> s;
        arr[i].setName(s);
        cout << "Age = ";
        cin >> arr[i].age;
        cout << "Gender = ";
        cin >> arr[i].gender;
    }
    cout << endl;
    for (int i = 0; i < 1; i++)
    {
        arr[i].printInfo();
    }
}