// Program to count the no. of ways to reach from start to end in 1D

#include <iostream>
using namespace std;

int countPath(int s, int e)
{
    if (s == e)
    {
        return 1;
    }
    if (s > e)
    {
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= 6; i++) // dice has number from one to 6
    {
        count += countPath(s + i, e);
    }
    return count;
}

int main()
{
    cout << countPath(1, 4) << endl;
    // for this function sum the count from 2 to end, 3 to end, 4 to end
}