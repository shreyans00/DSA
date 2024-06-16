// Memset function returns str, the pointer to the destination string
// memeset(void* str, int ch, size_t n)
// It copies a single character ch for n no. of times pointed by str[]

#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    char str[] = "geeksforgeeks";
    memset(str, 't', sizeof(str));
    cout << str;
    return 0;
}