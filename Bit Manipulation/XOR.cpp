#include <iostream>
using namespace std;

int computeXOR(int n)
{
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

/*
    How this function works?
    Number Binary-Repr  XOR-from-1-to-n
    1         1           [0001]  <----- Equals to 1
    2        10           [0011]
    3        11           [0000]  <----- We get a 0
    4       100           [0100]  <----- Equals to n
    5       101           [0001]  <----- Equals to 1
    6       110           [0111]
    7       111           [0000]  <----- We get 0
    8      1000           [1000]  <----- Equals to n
    9      1001           [0001]  <----- Equals to 1
    10     1010           [1011]
    11     1011           [0000] <------ We get 0
    12     1100           [1100] <------ Equals to n
*/

/* 
    To find XOR of more than two numbers, represent all numbers in binary representation
    Add 0’s before if necessary.
    Calculate number of 1’s in the corresponding bits.
    If it is even or zero then that XOR’ed bit is 0.
    If it is odd then that XOR’ed bit is 1.

    a^b is symbol of the operation
*/

int main()
{
    cout << computeXOR(6) << endl; // 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6  = 7
    cout << computeXOR(7) << endl; // 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 = 0
}