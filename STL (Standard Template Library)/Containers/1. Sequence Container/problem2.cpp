// A & B are two players & can take cards one after another
// ith card of both players have different value(biased). For A, Ai & for B, Bi
// You(A) have to take card such that the difference is maxm between you(A) & B

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first + a.second > b.first + b.second;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr.second;
    sort(arr[i].begin(), arr[i].end(), cmp);
}