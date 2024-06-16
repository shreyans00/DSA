#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int a = 0;
    cout << a - 1 << endl;

    vector<int> v;
    cout << v.size() - 1 << endl;
    // Possible fixes: use int or avoid subtracting integers
    cout << int(v.size()) - 1 << endl;
}