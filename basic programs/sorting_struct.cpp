// We discussed 3 methods to sort a structure by an element

#include <iostream>
#include <algorithm>
using namespace std;

struct Student
{
    string name;
    double height;
};

bool cmp(const Student &a, const Student &b)
{
    return a.height < b.height;
}

int main()
{
    struct Student st1, st2;
    st1.height = 19;
    st2.height = 16;

    // Method 1
    cout << "Check_cmp: " << cmp(st1, st2) << endl;
    cout << "Check_cmp: " << cmp(st2, st1) << endl;
    // if it returns 1 for both cmp(st1,st2) & cmp(st2,st1), then you will get runtime error

    struct Student st[2];
    st[0] = st1;
    st[1] = st2;
    cout << "Not Sorted: " << st[0].height << " " << st[1].height << endl;

    // Method 2
    sort(st, st + 2, cmp);
    cout << "Sorted: " << st[0].height << " " << st[1].height << endl; //sorted in ascending order of height

    // Method 3   Time Complexity:O(nlog(n))
    sort(st, st + 2,
         [](const Student &a, const Student &b)
         {
             return a.height > b.height;
         });
    cout << "Sorted_reverse: " << st[0].height << " " << st[1].height << endl; //sorted in ascending order of height
}