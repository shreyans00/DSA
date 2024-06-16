#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        bool swapped = false;
        // har baar sbse bada element last mai ja rha hai, so n-i-1 tk hi check krna kafi hai
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) // agr swapped true nhi hua mtlb purae ek traversal mai ek baar bhi swapping nhi hui, to loop se break kr do
            break;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
