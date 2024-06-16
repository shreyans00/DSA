#include <iostream>
using namespace std;

class Employee
{
    int id;
    static int count;

public:
    void setData()
    {
        cout << "enter id" << endl;
        cin >> id;
        count++;
    }
    void getData()
    {
        cout << "id is " << id << " and this is emp_no " << count << endl;
    }
};

int Employee::count; //Default value is 0
// int Employee::count(100)     counter starts from 100 in this case

int main()
{
    Employee amit, aman, aryan;
    amit.setData();
    amit.getData();
    aman.setData();
    aman.getData();
    aryan.setData();
    aryan.getData();
}