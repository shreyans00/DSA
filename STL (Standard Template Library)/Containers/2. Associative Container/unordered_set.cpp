// Hash table implementation
// Not sorted, unordered, can't perform binary search
// Average: O(1)   Worst: O(n)
// When size>=no. of buckets(load factor=1), capacity increases(~2x) & all the elements are rehashed

// In order to use unordered_set/map, classes must have hash function implemented (compiler implement for int, double, string, but not for pair, so have to create custom hashes for them)

#include <bits/stdc++.h>
using namespace std;

struct Hasher
{
    size_t operator()(pair<int, int> x) const
    {
        return x.first ^ x.second; // Hashing : XOR of 2 values
    }
};

int main()
{
    unordered_set<int> us;
    for (int i = 1; i <= 20; i++)
    {
        us.insert(i);
        cout << i << ' ' << us.bucket_count() << endl;
    }

    cout << "\nHasher class implementation" << endl;

    unordered_set<pair<int, int>, Hasher> us1;
    us1.insert({4, 2});
    us1.insert({0, 6});
    us1.insert({10, 12});
    cout << us1.bucket_size(6) << endl; // 3
}