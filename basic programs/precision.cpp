#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int q, p;
        cin >> q >> p;
        double tot = p * q; // with larger precision, use double
        if (q > 1000)
        {
            tot = tot - 0.1 * tot;
        }
        cout << fixed << setprecision(6) << tot << endl;
    }
}