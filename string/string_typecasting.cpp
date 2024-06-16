#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    // String to integer

    // Method 1
    string s1 = "123";
    int x = stoi(s1); // stoi function takes a string as an argument and returns its value
    int x2 = stoi("123.4");
    int x3 = stoi("123 ram");
    cout << x + 4 << " " << x2 << " " << x3 << endl;

    // Method 2
    string s2 = "123";
    stringstream obj(s2); // this obj has value 123
    int z = 0;
    obj >> z;
    cout << "Value of 123+2 : " << z + 2 << endl;

    // Method 3
    const char *s3 = "1234";
    int m;
    sscanf(s3, "%d", &m);
    cout << "Value of 1234+1 : " << m + 1 << endl;

    // Integer to string
    int y = 123;
    cout << to_string(y) + '4' << endl;

    return 0;
}