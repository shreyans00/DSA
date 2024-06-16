#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_map<char, int> mp;
    // initially all the mp[char]=0

    for (char i : s)
    {
        mp[i]++;
    }
    for (char i : s)
    {
        if (mp[i] != 0)
        {
            cout << i << mp[i] << " ";
            mp[i] = 0;
        }
    }
}
