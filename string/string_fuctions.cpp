#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1;
    getline(cin, s1); // used to take the string along with spaces
    string s2 = "country, mind i";

    s2.push_back('t'); // to push a letter at last in the string, also pop_back function can be used to remove the last letter

    s1.append(s2);
    //s1+s2 will do the same thing without any space
    cout << s1 << endl;

    cout << s2.size() << endl; // s2.length or s2.size()

    cout << s2.substr(2, 4) << endl; // return a substring of length 4 starting from 2nd index

    cout << s2.find("ntr") << endl; // returns the index position of first letter matched

    s2.erase(4, 5); // (starting index, no. of letters to be removed from that index)
    cout << s2 << endl;

    s2.insert(2, "mm");
    cout << s2 << endl;

    s2.clear();
    if (s2.empty())
        cout << "s2 is empty after clear" << endl;

    string s3(4, 'a'); // this makes a string in which "a"(single letter) is repeated 4 times
    cout << s3 << endl;

    if (s3.compare(s1))
        cout << "s1 and s3 are not equal" << endl;
}