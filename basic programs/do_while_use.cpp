// Program to rewrite numbers till we get 42

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, flag = 0;
    do
    {
        cin >> num;
        if (num < 100 and num > -100 and num != 42)
        {
            flag = 1;
            cout << num << "\n";
        }
        else
        {
            flag = 0;
        }
    } while (flag == 1);
    return 0;
}

/* Test Case:
1
2
88
42
99
*/