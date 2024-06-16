#include <iostream>
using namespace std;

class clss
{
    int a, b;

public:
    void setdata(int a, int y)
    {
        this->a = a; // this is a keyword (pointer) which points to the object which invokes the member function
        b = y;
    }
    clss &setdata2(int a, int y)
    {
        this->a = a; // this is a keyword (pointer) which points to the object which invokes the member function
        b = y;
        return *this;
    }
    void getdata()
    {
        cout << a << " " << b << endl;
    }
};

int main()
{
    float *ptr = new float(4.2); //we create an integer dynamically
    cout << *ptr << endl;

    int *arr = new int[5]; // it means 5 integer store krne ki capability kr do compiler bhai
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;

    delete arr; // delete[] arr;
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    cout << endl;

    clss *ptr2 = new clss;
    ptr2->setdata(5, 6); // same as *(ptr2).setdate(5,6)
    ptr2->getdata();
    ptr2->setdata2(8, 9);
    ptr2->getdata();
    ptr2->setdata2(7, 12).getdata();
}