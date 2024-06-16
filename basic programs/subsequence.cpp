#include <bits./stdc++.h>
using namespace std;

bool is_subsequence(string a, string b)
{
    if (b.size() > a.size())
        return 0;
    int it = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (it < b.size() && a[i] == b[it])
            it++;
    }
    if (it == b.size())
        return 1;
    else
        return 0;
}

int main()
{
    cout << is_subsequence("start", "tsrt");
}