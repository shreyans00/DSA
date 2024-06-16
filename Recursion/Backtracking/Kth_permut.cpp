#include <bits/stdc++.h>
using namespace std;

string getPermutationAtK(int n, int k)
{
    int fact = 1;
    string res = "";
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
        v.push_back(i);
    }

    k--; // since we are using zero based indexing
    while (v.size() > 0)
    {
        fact = fact / v.size();
        res += to_string(v[k / fact]);
        v.erase(v.begin() + k / fact); // jo number milega usko erase kr dena
        k = k % fact;
    }
    return res;
}

int main()
{
    int n = 4, k = 9;
    string kthsequence = getPermutationAtK(n, k);
    cout << kthsequence << endl;
    return 0;
}