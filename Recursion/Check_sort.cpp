// Program to check whether an array is sorted in ascending order or not

#include <iostream>
using namespace std;

bool check(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }
    int rest_array = check(arr + 1, n - 1);
    return (rest_array and arr[0] < arr[1]);
}

int main()
{
    int arr[5] = {1, 3, 9, 6, 35};
    if (check(arr, 5))
    {
        cout << "sorted" << endl;
    }
    else
    {
        cout << "unsorted" << endl;
    }
    return 0;
}