// reverse a list & string

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {14, 11, 3, 4, 2, 5, 1, 25};
    int n = sizeof(a) / sizeof(a[0]);
    reverse(a, a + n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    char s[] = "hello there"; //char not string
    reverse(s, s + strlen(s));
    cout << "\n"
         << s << endl;
    return 0;
}