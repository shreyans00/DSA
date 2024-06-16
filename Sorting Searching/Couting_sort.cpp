#include <bits./stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i <= b; i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[] = {1, 3, 6, 9, 9, 3, 5, 9};
    int arr2[10] = {0};
    REP(i, 0, 7)
    {
        int val = arr[i];
        arr2[val]++;
    }
    REP(i, 1, 9)
    {
        while (arr2[i]--)
        {
            cout << i << " ";
        }
    }
}