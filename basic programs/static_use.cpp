#include <bits/stdc++.h>
using namespace std;

// Static variables in a Function:
// For static variable, space gets allocated for the lifetime of the program.
// Even if the function is called multiple times, space for the static variable is allocated only once and the value of variable in the previous call gets carried through the next function call.

void func()
{
    static int x = 0;
    cout << x << " ";
    x++;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        func();
    }
    return 0;
}