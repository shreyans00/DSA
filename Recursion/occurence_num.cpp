// Program to find the first and last occurrence of a number in an array
// {4,2,1,2,5,2,6} - first occurrence of 2 is at index 1 and last occurrence of 2 is at index 5

#include <iostream>
using namespace std;

int pos = 0;
int first(int arr[], int n)
{
    if (n == 0)
    {
        cout << "2 is not the array";
        return false;
    }
    if (arr[0] == 2)
    {
        return pos;
    }
    pos++;
    first(arr + 1, n - 1);
}

int firstocc(int arr[], int n, int pos, int key) //BEST METHOD
{
    if (pos == n)
        return -1;
    if (arr[pos] == key)
        return pos;
    firstocc(arr, n, pos + 1, key);
}

int last(int arr[], int n)
{
    if (n == 0)
    {
        cout << "2 is not the array";
        return false;
    }
    if (arr[n - 1] == 2)
    {
        pos = n - 1;
        return pos;
    }
    last(arr, n - 1);
}

int lastocc(int arr[], int n, int pos, int key)
{
    if (pos == n)
        return -1;
    if (arr[pos] == key)
        return pos;
    lastocc(arr, n, pos - 1, key);
}

int lastocc2(int arr[], int n, int pos, int key) //BEST METHOD
{
    if (pos == n)
        return -1;
    int restArray = lastocc2(arr, n, pos + 1, key);
    if (restArray != -1)
    {
        return restArray;
    }
    if (arr[pos] == key)
    {
        return pos;
    }
    return -1;
}

int main()
{
    int arr[] = {4, 2, 1, 2, 5, 2, 6};
    cout << first(arr, 7) << endl;
    cout << last(arr, 7) << endl;

    cout << firstocc(arr, 7, 0, 2) << endl;
    cout << lastocc(arr, 7, 6, 2) << endl;
    cout << lastocc2(arr, 7, 0, 2) << endl;
}