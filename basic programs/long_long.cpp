#include <bits./stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a = 123456789;
    long long b = a * a;
    // Even though the variable b is of type long long, both numbers in the expression a*a are of type int and the result is also of type int
    cout << b << "\n"; // -1757895751
    long long c = (long long)a * a;
    cout << c << "\n"; // 15241578750190521
}