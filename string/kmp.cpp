#include <bits/stdc++.h>
using namespace std;

void computeLPS(string t, vector<int> &lps)
{
    lps[0] = 0;  // no matching prefix which is also suffix for 1st char
    int len = 0; // length of matching prefix which is also suffix
    int i = 1;
    while (i < t.size())
    {
        if (t[i] == t[len])
        {
            lps[i] = len + 1;
            len++, i++;
        }
        else
        {                           // mismatch
            if (len != 0)           // Whenever a mismatch occurs and we already progressed in length, we have to go backward in direction
                                    // But we can't go back to len=0 because that would not give the longest prefix which is also suffix
                                    // ex: aabaaac - 0101220
                len = lps[len - 1]; // to reduce the len value so as to find lps
            else
            {
                lps[i] = 0; // len=0 & mismatch, it means lps should be 0
                i++;        // inc i to compare nxt char
            }
        }
    }
    cout << "LPS array: ";
    for (int i = 0; i < lps.size(); i++)
        cout << lps[i] << " ";
    cout << "\n";
}

void KMPSearch(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<int> lps(m, 0); // same length as that of pattern
    computeLPS(t, lps);    // lps of pattern
    int i = 0, j = 0;      // start from both pattern and text
    while (i < n)          // scan through entire text
    {
        if (s[i] == t[j]) // if char of pattern and text match
            i++, j++;     // inc both
        else
        {
            if (j != 0)
                j = lps[j - 1]; // we take the value of (j-1)th index of lps, just prev where a mismatch occurs
            // It will tell us the length of the longest prefix which is also suffix untill (j-1)th index
            // Mtlb j-1 aur usse kuch (exact value is lps[j-1]) pehle wale characters suru ke utne hi char se match kr rhe honge
            else     // first char itself doesn't match
                i++; // just go to nxt char
        }
        if (j == m)
        {
            cout << "Starting matched index: " << i - j << endl; // starting index where pattern matches
            j = lps[j - 1];
        }
    }
}

void solve()
{
    string s = "onionionspl", t = "onions";
    KMPSearch(s, t);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}