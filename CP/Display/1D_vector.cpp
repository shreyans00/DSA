#include <bits/stdc++.h>
using namespace std;

void display(vi v)
{
    loop(i, 0, v.size())
    {
        pr1(v[i]);
    }
    cout << "\n";
}

void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}