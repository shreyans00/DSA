// Program to generate all possible subsets of a set

#include <iostream>
using namespace std;

void subsets(int a[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    // 1<<n is similar to 2^n
    // if array contains n elements they total subarrays are 2^n (one is null set)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                cout << a[j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a[4] = {1, 2, 3, 4};
    subsets(a, 4);
    return 0;
}