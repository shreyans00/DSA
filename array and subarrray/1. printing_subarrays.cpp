// Program to print all the subarrays in the array

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

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            { // this loop is for changing the starting(i) and the ending(j) position of each subarray
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
}