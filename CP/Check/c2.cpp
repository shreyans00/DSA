#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string s;
    int n, m;

    bool func(int i, int j, int k, vector<vector<char>> &v)
    {
        if (k == s.size())
            return true;
        if (i < 0 || j < 0 || i >= m || j >= n || v[i][j] != s[k])
            return false;
        v[i][j] = '#'; // Mark the visited cell
        bool st = func(i + 1, j, k + 1, v) || func(i, j + 1, k + 1, v) || func(i - 1, j, k + 1, v) || func(i, j - 1, k + 1, v);
        v[i][j] = s[k]; // Restore the cell
        return st;
    }

    bool exist(vector<vector<char>> &v, string word)
    {
        m = v.size();
        n = v[0].size();
        s = word;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == s[0] && func(i, j, 0, v))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> grid = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "SEE";

    bool found = solution.exist(grid, word);
    if (found)
    {
        cout << "Word exists in the grid." << endl;
    }
    else
    {
        cout << "Word does not exist in the grid." << endl;
    }

    return 0;
}
