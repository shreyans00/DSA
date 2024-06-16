#include <iostream>
using namespace std;

// function to get bit at specific position
int getBit(int n, int pos)
{
    return (n >> pos) & 1; // use this      here n is written in binary form
    // Right shift n 'pos' times and check the first bit. By shifting, we mean we remove bits after pos and so we take '&' of 'pos' bit with 1
    // eg: 1100   n>>2    =>   11|00   =>   11 & 1 = 1

    // return ((n & (1 << pos)) != 0);
    // 1 << pos   se sirf whi position pr 1 rhega jiska bit pta krna chah rhe hai
    // uske sath (n &) kr denge agar wo 1 aaya to uss position pr 1 hoga
    // aur agar 0 aaya to uss position pr 0 hoga
}

// function to set bit (either it is 1 or 0, change it to 1) at specific position
int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

// function to clear bit (set it to 0) at specific position
int clearBit(int n, int pos)
{
    return (n & ~(1 << pos));
    // negation ensures that other elements remains the same while pos element set to 0
}

// function to update a bit (to value) at a specific position
// for this, first clear bit and then set bit (to value)
int updateBit(int n, int pos, int value)
{
    n = n & ~(1 << pos);
    return (n | (value << pos));
}

// function to toggle a bit at specific position
// Bitwise XOR operation between n & (1<<pos) toggle the bit
int toggleBit(int n, int pos)
{
    return (n xor (1 << pos));
}

// function to remove last 1th bit     110100(n) & 110011(n-1) = 110000
// Also this can be used to count no. of 1 bit in the number (popcount)
int removelast1thBit(int n)
{
    return (n & n - 1);
}

int main()
{
    cout << getBit(5, 2) << endl;       // 5 = 101
    cout << setBit(5, 1) << endl;       // 111 = 7
    cout << clearBit(5, 0) << endl;     // 100 = 4
    cout << updateBit(5, 2, 0) << endl; // 001 = 1
}