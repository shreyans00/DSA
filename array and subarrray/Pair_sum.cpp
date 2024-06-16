// if we use nested loops, then complexity is O(n2)
// Let's optimise it to O(n)
// Condn: Array must be sorted

#include <iostream>
#include <climits>
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
    int k;
    cin >> k;

    int s = 0, e = n - 1;
    bool flag = 0;
    while (s < e)
    {
        if (a[s] + a[e] == k)
        {
            cout << s << " " << e << endl;
            flag = 1;
            break;
        }
        else if (a[s] + a[e] < k)
        {
            s++;
        }
        else
        {
            e--;
        }
    }
    if (flag == 1)
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }
    return 0;
}