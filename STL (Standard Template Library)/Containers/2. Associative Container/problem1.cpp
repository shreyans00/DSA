// Program to insert, remove, find min,max,sum,no. of distinct elements & freq of just greater or equal & just lower val of a key from a bag

#include <bits/stdc++.h>
using namespace std;

struct bag
{
    int minv = INT_MAX;
    map<int, int> mp;
    int sum;
    bag()
    { // O(1)
        sum = 0;
        mp.clear();
    }
    void insert(int x)
    { // O(log n) since insertion inside map takes log(n) time complexity
        mp[x]++;
        sum += x;
    }
    void remove(int x)
    { // O(log n)
        if (mp.find(x) == mp.end())
            return; // map find take O(log n)
        mp[x]--;    // map access take O(log n)
        if (mp[x] == 0)
        {
            mp.erase(x); // erase take O(log n)
        }
        sum -= x;
    }
    int getMin()
    { // O(1)
        if (mp.empty())
            return -1;
        return mp.begin()->first;
    }
    int getMax()
    { // O(1)
        if (mp.empty())
            return -1;
        auto it = mp.end(); // all the iterators will fetch in O(1)
        it--;
        return it->first;
    }
    int getsum()
    { // O(1)
        return sum;
    }
    int getFreqofNextGreaterEq(int x)
    {                                // O(log n)
        auto it = mp.lower_bound(x); // lower_bound is sth similar to binary search, so takes O(log n)
        if (it == mp.end())
            return 0;
        return it->second;
    }
    int getFreqofPrevSmallerEq(int x)
    { // O(log n)
        auto it = mp.upper_bound(x);
        if (it == mp.begin())
            return 0;
        it--;
        return it->second;
    }
    void display()
    {
        for (auto i : mp)
        {
            cout << i.first << '\t' << i.second << '\n';
        }
        cout << endl;
    }
};

int main()
{
    struct bag bg;
    // bg.mp;
    bg.mp{{1, 10}, {2, 20}, {3, 30}, {2, 30}, {4, 40}, {5, 50}};
    bg.insert(6);
    // bg.remove(4);
    bg.display();
    return 0;
}