#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "ghrtggh hrtthh";
    int size = s.size();

    auto m = 'd' - 'a'; // outputs an integer 3
    auto m2 = 'a' - 2;  // outputs an interger 95(97-2)

    int freq[size];
    for (int i = 0; i < size; i++)
        freq[i] = 0;

    for (int i = 0; i < size; i++)
        freq[s[i] - 'a']++;

    char ans = 'a';
    int maxF = 0;

    for (int i = 0; i < size; i++)
    {
        if (freq[i] > maxF)
        {
            maxF = freq[i];
            ans = i + 'a';
        }
    }

    cout << maxF << " " << ans << endl;
    return 0;
}