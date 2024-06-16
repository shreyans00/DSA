// Print all possible words from phone digits of an old phone
// characters corres to {0,1,2,3,4,5,6,7,8,9} -- {"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}
// from digits 2 and 3, we get combn like ad,ae,af,bd,de,bf,cd,ce,cf

#include <iostream>
using namespace std;

string keypadArr[] = {"", "./", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int count = 0;
void keypad(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        count++;
        return;
    }
    char ch = s[0];
    string code = keypadArr[ch - '0'];
    string ros = s.substr(1);

    for (int i = 0; i < code.length(); i++)
    {
        keypad(ros, ans + code[i]);
    }
}

int main()
{
    keypad("23", "");
    cout << count << endl;

    char a = '2';
    cout << a - '0'; // method to convert character to integer: ch-'0'
}