#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cin >> key;

    bool flag = 0;
    int f = 0, l = n - 1;
    while (f <= l)
    {
        int mid = (f + l) / 2;
        if (a[mid] == key)
        {
            flag = 1;
            break;
        }
        else if (key > a[mid])
        {
            f = mid + 1;
        }
        else
        {
            l = mid - 1;
        }
    }
    if (flag == 1)
        cout << "found\n";
    else
        cout << "not found\n";

    // Method 2
    // int k = 0;
    // for (int b = n / 2; b >= 1; b /= 2)
    // {
    //     while (k + b < n && a[k + b] <= key)
    //         k += b;
    // }
    // if (a[k] == key)
    // {
    //     cout << "found\n";
    // }
    // else
    // {
    //     cout << "not found\n";
    // }

    // Both methods have time complexity of O(log(n))

    return 0;
}