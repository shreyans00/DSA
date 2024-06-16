#include <iostream>
using namespace std;

void reverse(string s) //BETTER
{
    if (s.length() == 0)
    {
        return;
    }
    string ros = s.substr(1); // substr(index position from where you want your string)
    reverse(ros);
    cout << s[0];
}

int rev(char s[], int start, int end)
{
    if (start >= end)
    {
        return 0;
    }
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    rev(s, start + 1, end - 1);
}

int main()
{
    char s[] = "binod";
    rev(s, 0, 4);
    cout << s << endl;
    reverse("binod");
    return 0;
}