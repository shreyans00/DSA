// Generate all substrings of a string
// We start with an empty string and then either letter will be added or not in every case
#include <iostream>
using namespace std;

void substring(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    substring(ros, ans);      // letter is not added here
    substring(ros, ans + ch); // letter is added here
}

int main()
{
    string s = "ABC";
    substring(s, "");
}