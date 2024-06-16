#include <bits./stdc++.h>
#include <map>

using namespace std;

void display(map<int, int> m)
{
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << '\t' << it->second << '\n';
    }
    cout << endl;
    // for (auto i : m)
    // {
    //     cout << i.first << '\t' << i.second << '\n';
    // }
    // cout << endl;
}

int main()
{
    map<int, int> m;

    m.insert(pair<int, int>(1, 10));
    m.insert({2, 20});
    m.insert({3, 30});
    m.insert({4, 30});
    m.insert({5, 50});
    m.insert({6, 60});

    m.insert({2, 21}); // doesn't insert different value to same key
    display(m);

    // to print value corres to a particular key
    cout << m.find(5)->second << "\n\n"; // m.find() basically returns the iterator, if not present then it equals m.end()

    // remove element with key = 4
    cout << m.erase(3) << "\n\n"; //return 1 and erase that key-value pair(if key available) otherwise returns 0 and do nothing
    display(m);

    // remove all elements upto element(less than) with key=3
    m.erase(m.begin(), m.find(4));

    cout << (m.count(2) ? "exists" : "not exists") << endl;

    // copy elements from m to m2
    map<int, int> m2(m.begin(), m.end());
    // mp.end() : gives the last+1 iterator, so store it in "it" & do it-- or can use mp.rbegin();

    int key = 5;
    auto it = m.lower_bound(key); // can't use lower_bound(m.begin(),m.end(),key) as it runs like a tree, but can't jump steps ahead. It is not a like a random iterator
    if (it != m.end())
    {
        cout << "\n"
             << it->second << endl;
    }
}