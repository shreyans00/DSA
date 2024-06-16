#include <bits/stdc++.h>
using namespace std;

void display_method1(vector<vector<int>> vect)
{
    // We are getting vect1D vectors of type vector<int> from the 2D vector vect and
    // int elements to x from the vector<int> vect 1D vector.

    for (vector<int> vect1D : vect) // can also use also auto
    {
        for (int x : vect1D)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

void display_method2(vector<vector<int>> vect) // like an array
{
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> vect{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    display_method1(vect);

    // To create a vector of size n*m
    int n = 3, m = 2;
    vector < vector<int> v(n, vecto<int>(m));
}
