// Program to count the no. of ones in binary representation of a number

#include <iostream>
using namespace std;

// n and n-1 has same bits except the rightmost set bit

int numberofones(int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main()
{
    cout << numberofones(19) << endl; // 19 = 10011
    return 0;
}