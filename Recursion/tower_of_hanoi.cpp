// Tower of Hanoi - to transfer A to C we need a helper B such that n-1 transfer from A to B, then rest one to C and again n-1 from B to C

#include <iostream>
using namespace std;

void towerofHanoi(int n, char src, char dest, char helper)
{
    if (n == 0)
        return;
    towerofHanoi(n - 1, src, helper, dest);
    cout << "Move " << n << " from " << src << " to " << dest << endl;
    towerofHanoi(n - 1, helper, dest, src);
}

int main()
{
    towerofHanoi(3, 'A', 'C', 'B');
}