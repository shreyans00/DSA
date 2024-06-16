#include <iostream>
using namespace std;

/*
Logic
    1. Take XOR of all the elements and let that xor value be x.
        All the repeating elements will get nullified and xor of only two unique elements will last.

    2. There will be at least one bit set in x. Using that set bit,
        divide the original set of numbers into two sets
        a. First set which contains all the elements with that bit set.
        b. Second set which contains all the elements with that bit unset.

    3. XOR of both the sets individually give both unique numbers.
*/

int setBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

void unique(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }

    int tempxor = xorsum; // here xorsum has xor of 2 unique values
    int setbit = 0;
    int pos = 0;

    while (setbit != 1)
    {
        setbit = xorsum & 1; // setbit becomes 1 when it encounters a set bit(i.e. 1)
        pos++;
        xorsum = xorsum >> 1; // shift right by 1 unit
    }
    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if (setBit(arr[i], pos - 1))
        {
            newxor = newxor ^ arr[i];
        }
    }
    cout << newxor << endl;
    cout << (tempxor ^ newxor) << endl;
}
int main()
{
    int arr[] = {1, 2, 3, 1, 2, 3, 5, 7};
    unique(arr, 8);
    return 0;
}