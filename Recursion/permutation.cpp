// Permutations of a string

#include <iostream>
using namespace std;

void permut(string s, string ans) // we store our permutation in string ans
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];                                // we fix a character
        string ros = s.substr(0, i) + s.substr(i + 1); // fix se pehle ki string + fix se baad wali string
        permut(ros, ans + ch);
    }
}

int main()
{
    permut("ABC", "");
}