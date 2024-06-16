#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // Time complexity: summation(nCi*2^i) from 0 to n ie O(3^n)
    // This outer loop runs through all possible binary masks from 0 to 2^n - 1.
    // Each mask represents a subset of the elements, where the i - th bit of mask being set(1) corresponds to the i - th element being included in the subset, and the bit being unset(0) means the element is not included in the subset.
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int sub = mask; sub; sub = (sub - 1) & mask)
        {
            // (sub - 1) effectively flips the rightmost set bit of sub to 0, thus generating the next smaller subset.

            // (sub - 1) & mask : ye ek ek krke mask ke saare set bits hta dega (hmesa next set bit dekhega mask ka)
            // ex: 1101->1100->1000->0000 isse inspite of doing operation with everyone, sirf set bit (jo subset mai included hai unse kaam kr liya hmne)
        }
    }
}
