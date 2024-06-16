#include <bits./stdc++.h>
using namespace std;

bool khalirowcol(int grid[][9], int &r, int &c)
{
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            if (grid[r][c] == 0)
                return true;
        }
    }
    return false;
}

bool isvalid(int grid[][9], int r, int c, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[r][i] == num)
            return false;
    }
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][c] == num)
            return false;
    }
    int rstart = r - r % 3, cstart = c - c % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[rstart + i][cstart + j] == num)
                return false;
        }
    }
    return true;
}

bool sudoko(int grid[][9])
{
    int r, c;
    if (!khalirowcol(grid, r, c))
        return true;
    for (int i = 1; i <= 9; i++)
    {
        if (isvalid(grid, r, c, i))
        {
            grid[r][c] = i;
            if (sudoko(grid))
                return true; // hme saare possible grids nhi nikalne, so jis value pe bhi sudoko(grid) true ho rha ho, whi return kr do
        }
        grid[r][c] = 0; // backtracking (since our assumption is wrong & we go for next assumption)
    }
    return false;
}

void printgrid(int grid[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (sudoko(grid))
    {
        printgrid(grid);
    }
    else
    {
        cout << "Not possible to solve the sudoko" << endl;
    }
    cout << "hel" << endl;
    return 0;
}