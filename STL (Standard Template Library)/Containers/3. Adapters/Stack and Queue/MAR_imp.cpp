#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int mah(vector<int> v)
{
    stack<int> s;
    vector<int> left, right;
    int area = 1;

    // left nearest smallest

    for (int i = 0; i < v.size(); i++)
    {
        while (!s.empty() && v[s.top()] >= v[i])
            s.pop();

        s.empty() ? left.push_back(-1) : left.push_back(s.top());
        s.push(i);
    }

    while (!s.empty())
        s.pop();

    // right nearest smallest

    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && v[s.top()] >= v[i])
            s.pop();

        s.empty() ? right.push_back(v.size()) : right.push_back(s.top());
        s.push(i);
    }
    reverse(right.begin(), right.end());

    for (int i = 0; i < v.size(); i++)
        area = max(area, v[i] * (right[i] - left[i] - 1));

    return area;
}

// histogram creation function

void hist(vector<vector<int>> v)
{
    vector<int> temp;
    temp = v[0];
    int a = mah(temp);
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == 1)
                temp[j] += v[i][j];
            else
                temp[j] = 0;
        }
        a = max(a, mah(temp));
    }
    cout << "Maximum area rectangle in the binary matrix is: " << a;
}

int main()
{
    vector<vector<int>> vect{
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1}};
    hist(vect);
    return 0;
}