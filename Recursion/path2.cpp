// Program to count the no. of ways to reach from start to end in 2D

#include <iostream>
using namespace std;

int countPath(int n, int i, int j)
{
    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }
    if (i >= n || j >= n)
    {
        return 0;
    }
    return (countPath(n, i + 1, j) + countPath(n, i, j + 1));
}

int main()
{
    cout << countPath(3, 0, 0) << endl;
}