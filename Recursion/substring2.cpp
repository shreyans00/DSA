// Generate all substrings of a string alongwith ASCII code
// To convert a number into string is -- to_string(number)

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
    int asc = ch;
    string ros = s.substr(1);
    substring(ros, ans);                  // Neither letter, nor ascii added here
    substring(ros, ans + ch);             // letter is added here
    substring(ros, ans + to_string(asc)); // ascii is added here
}

int main()
{
    string s = "AB";
    substring(s, "");
}