/*
  Vectors are like dynamic array
  vector<data_type> vector_name;
  Vectors can be compared directly (lexicographical order) using comparison operators
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void display(vector<T> &v)
{
    // Method 1
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }

    // Method 2
    // typename vector<T>::iterator it;      // We need to use typename to tell the compiler that vector<type>::iterator is a type, otherwise the compiler will assume it's a variable or function.
    // for (it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    // Method 3
    for (auto element : v) // hm compiler ko bol rhe hai bhai tu khud decide krle le data_type kaun sa hai accor to initialisation
    {
        cout << element << " ";
    }
    cout << endl;
}

int main()
{
    // Ways to create a vector
    vector<int> vec1;        //zero length integer vector
    vector<char> vec2(4);    //4-element character vector
    vector<char> vec3(vec2); //4-element character vector from vec2
    vector<int> vec4(6, 3);  //size:6 ,  initial value:3
    vector<int> vec5 = {2, 4, 2, 5, 1};

    int element, size;
    cout << "Size : " << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Element to add : ";
        cin >> element;
        vec1.push_back(element); // to add elements at the back
    }
    cout << "Last element :" << vec1.back() << "\n";
    display(vec1);
    vec1.pop_back();
    display(vec1);

    vector<int>::iterator iter = vec1.begin(); // iter points to first element
    vec1.insert(iter + 1, 5, 14);              // 5 times 14 inserted at (iter+1)th i.e 2nd position
    display(vec1);

    sort(vec1.begin(), vec1.end());   // to sort in ascending order
    sort(vec1.rbegin(), vec1.rend()); // to sort in reverse order
    // reverse(vec1.begin(), vec1.end())    // to sort in reverse order
    random_shuffle(vec1.begin(), vec1.end()); // to suffle the elements in random order

    display(vec1);
    return 0;
}
