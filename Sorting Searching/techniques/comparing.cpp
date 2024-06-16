#include <bits./stdc++.h>
using namespace std;

struct prob
{
    int s, t, d
};

bool cmp(prob a, prob b)
{
    return a.t * b.d < b.t * a.d; // a.t / a.d <= b.t / b.d
}

int main()
{
    int n;
    cin >> n;
    vector<prob> v;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto x : v)
        cout << x.s << " " << x.t << " " << x.d << endl;
}