#include <bits/stdc++.h>
using namespace std;

void display2D(vvi v)
{
    loop(i, 0, v.size())
    {
        loop(j, 0, v[0].size())
        {
            prs(v[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";
}
