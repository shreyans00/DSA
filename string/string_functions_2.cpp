#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s1 = "nfGvaGE@#Agvf";

    // cout << s1.begin() << " " << s1.end() << endl;

    sort(s1.begin(), s1.end()); // sort these according to their ascii values
    cout << s1 << endl;

    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    cout << s1 << endl;

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    cout << s1 << endl;

    reverse(s1.begin(), s.end()); // reverse a string

    reverse(s1.begin() + 2, s.begin() + 5); // reverse a substring

    string s2 = "9353567783";
    // getline(cin,s2);
    sort(s2.begin(), s2.end(), greater<int>()); // sort(s2.rbegin(),s2.rend())
    cout << s2 << endl;

    sort(s2.begin(), s2.end());
    cout << s2 << endl;

    return 0;
}