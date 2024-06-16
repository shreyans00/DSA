// Sort using sort function

#include <bits/stdc++.h>
/* or can use below modules to have access to sort function
#include <iostream>
#include <algorithm>
*/
using namespace std;

int main()
{
    int t;
    cin >> t;
    int arr[t];
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + t);
    for (int i = 0; i < t; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}