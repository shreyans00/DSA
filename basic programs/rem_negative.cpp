#include <bits./stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x = -8, m = 3;
    x = x % m;
    if (x < 0)
        x += m;
    cout << x;
}