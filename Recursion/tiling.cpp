// Count the number of ways to tile the 2xn board using 2x1 tile

#include <iostream>
using namespace std;

int tile(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return (tile(n - 1) + tile(n - 2)); // (n-1) columns left if we choose vertical, and (n-2) columns left if we choose horizontal
}

int main()
{
    cout << tile(4);
}