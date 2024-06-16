// Program to check if a given number is power of 2

#include <iostream>
using namespace std;

void Ispower2(int n)
{
    if (n & (n - 1))
        cout << "It is not a power of 2" << endl;
    else
        cout << "It is power of 2" << endl;
}

/*
    How does this function works?

    n & (n - 1) has same bits as n except the rightmost set bit(i.e rightmost 1)
    and sets the first set-bit to zero and rest right sets to 1.
    Explanation: n = XXX1000
    n - 1 = XXX0111
    n & ( n - 1 ) = XXX0000

    Now, in power of 2's, only the leftmost element has set bit(i.e 1)
    i.e n has only one set bit, and n-1 will have all set bits after that position,
    then n & ( n - 1 ) would be zero
*/

int main()
{
    Ispower2(16);
}