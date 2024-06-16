// Program to print n numbers in ascending or descending order

#include <iostream>
using namespace std;

void asc(int n)
{
    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }
    asc(n - 1);
    cout << n << " ";
    return;
}

void desc(int n)
{
    cout << n << " ";
    if (n == 1)
    {
        return;
    }
    desc(n - 1);
    return;
}

int main()
{
    asc(20);
    cout << endl;
    desc(20);
}