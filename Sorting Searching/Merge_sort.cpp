/*
Time Complexity in recursive function (Master's Theorem): T(n) = a T(n/b) + c O(n)
=>   n size ke problem ko solve krne mei utna time lga jitna a times n/b size ko krne mei lgta plus O(n) dono ko compile krne ki time complexity hai
In merge sort, a = 2, b = 2, c = 1   ->  T(n) = 2 T(n/2) + O(n)   ->   c = logb(a)        {O(n) is the time complexity of merging these 2 divided parts}
Therefore, time complexity in merge sort is O(nLog2(n))   {formula if above condition satisfy}
*/

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1], b[n2]; // temp arrays
    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];
    int k = l, i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) // Time Complexity in recursive function (Master's Theorem): T(n) = a T(n/b) + c O(n)
// a = 2, b = 2, c = 1   ->  T(n) = 2 T(n/2) + O(n)   ->   c = logb(a)   =>  O(n logn)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main()
{
    int arr[] = {53, 25, 63, 24, 63, 15};
    merge_sort(arr, 0, sizeof(arr) - 1);

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}