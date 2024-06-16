#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/* 
The useful classes for working with files in C++ are:
1. fstreambase
2. ifstream --> derived from fstreambase
2. ofstream --> derived from fstreambase

Two ways to handle a file:
1. Using the constructor
2. Using the member function
*/

int main()
{
    string s1 = "Write into file";
    // Opening files using constructor and writing in it
    ofstream outkro("input2.txt");
    outkro << s1;
    outkro.close();
    // outkro << s1; //now outkro won't work

    string s2;
    // Opening files using constructor and reading from it
    ifstream inkro("output2.txt");
    // inkro >> s2;        // to get a word and write into string s2
    getline(inkro, s2); // to get a line and write into string s2
    cout << s2 << endl;

    ifstream in;
    string s3;
    // Opening files using function
    in.open("output2.txt");
    // storing lines in st till end of file
    while (in.eof() == 0)
    {
        getline(in, s3);
        cout << s3 << endl;
    }

    return 0;
}
