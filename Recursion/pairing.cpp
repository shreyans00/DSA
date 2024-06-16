// Number of ways in which n friends can be single or paired up

#include <iostream>
using namespace std;

int pairing(int n)
{
    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }
    return (pairing(n - 1) + pairing(n - 2) * (n - 1)); // (n-1) if we select the 1st person to be single , (n-2)*(n-1) if we select 1st to be paired with anyone of (n-1) and then pairing rest (n-2)
}

int main()
{
    cout << pairing(4);
}