#include <bits./stdc++.h>
#include <vector>
using namespace std;

bool myCompare(pair<int, int> p1, pair<int, int> p2) // to compare which pair's first element is more
{
    return (p1.first < p2.first);
}

int main()
{
    //Pair class couples together the pair of values, which may be of different types

    // pair<int, char> p;
    // p.first = 3;
    // p.second = 'f';

    int arr[] = {4, 33, 63, 15, 74, 63, 26, -2};
    vector<pair<int, int>> v;
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        // v.push_back(make_pair(arr[i], i)); // make_pair() is used to couple the values
        v.push_back({arr[i], i});
    }
    // sort(v.begin(), v.end(), myCompare);
    sort(v.begin(), v.end(), less<pair<int, int>>()); // sort in ascending order of 1st int (arr values)
    // sort(v.begin(), v.end(), greater<pair<int, int>>()); // sort in descending order of 1st int

    // from this we don't loose original index position of respective element
    cout << v[0].first << endl;    // this is the smallest value
    cout << v[0].second << "\n\n"; // this is the corresponding position

    for (int i = 0; i < v.size(); i++) // v.size()=8
    {
        arr[v[i].second] = i; // second means index here
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << arr[i] << " "; // this gives the index order to make it sort
    }

    // To sort a pair
    // sort according to their first elements. If first elements of two pairs are equal, they are sorted according to their second elements
    vector<pair<int, int>> vec;
    vec.push_back({1, 5});
    vec.push_back({2, 3});
    vec.push_back({1, 2});
    sort(v.begin(), v.end()); //  (1,2), (1,5) and (2,3)

    return 0;
}