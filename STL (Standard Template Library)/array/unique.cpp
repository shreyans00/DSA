// to remove consecutive equal elements & returns a pointer to the end of the range
// To get the distinct elements in the range, sort the range first then apply "unique"

#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[] = "abcccdddbaa";

    int newlen = unique(s, s + strlen(s)) - s;
    // unique(s, s + strlen(s))   :  return the iterator at last+1, that's why need to subtract iterator at first
    s[newlen] = 0; // mtlb s ki size km hokr newlen itni ho jayegi  (remember this method to reduce size of string)

    // One line syntax :
    // *unique(s, s + strlen(s)) = 0;

    cout << s << endl;

    return 0;
}