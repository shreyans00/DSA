// Useful to store extra information other than the key

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    // Map is an associative array in the sorted order of key, here string
    map<string, int> marksMap;
    marksMap["Atul"] = 58;
    marksMap["Rohit"] = 57;
    marksMap["Kishlay"] = 78;
    marksMap["Aditya"] = 65;
    marksMap["Sachin"] = 53;

    auto it = marksMap.find("Raj");
    cout << (it == marksMap.end()) << "\n\n"; // returns 1 since no name Raj present

    marksMap.insert({{"Bishop", 52}, {"Minal", 70}});

    map<string, int>::iterator iter;
    for (iter = marksMap.begin(); iter != marksMap.end(); iter++)
    {
        // cout << (*iter).first << " " << (*iter).second << "\n";
        cout << iter->first << " " << iter->second << "\n";
    }

    auto it1 = marksMap.begin();
    it1++;
    it1->second = 60;
    cout << "\n"
         << it1->first << " " << marksMap["Atul"] << "\n\n";
    // it1->first = "Atif";  you can't change key, it shows compilation error

    cout << "Size is: " << marksMap.size() << endl;
    cout << "Maxm size is: " << marksMap.max_size() << endl;
    cout << "Empty's return value is: " << marksMap.empty() << endl; // 0 means it is not empty

    return 0;
}
