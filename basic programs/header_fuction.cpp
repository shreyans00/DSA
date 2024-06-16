#include <iostream> //header file for taking input and printing output, can also use "iostream", otherwise write std::cout
#include <bits/stdc++.h>
#include <climits>
#include <math.h>  // we can use math.h or cmath -- both are allowed
#include <fstream> // to include file functions like ofstream and instream
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional> // to use greater<T>

using namespace std;

int main()
{
     int max = INT_MAX;
     float min = INT_MIN;
     cout << max << endl
          << min << endl; // endl is used to end the line i.e. line break

     cout << std::max(2, -3) << endl
          << std::min(2, -3);

     printf("We can use printf as well in cpp\n");
     return 0;
}
