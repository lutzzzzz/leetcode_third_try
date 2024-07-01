#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> result;
    bool isValid(int row, int col, vector<string> &path)
    {
        for (int i = 0; i < row; i++)
        {
            if (path[i][col] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (path[i][j] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < path.size(); i--, j++)
        {
            if (path[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    void trackback(int line, vector<string> &path)
    {
        if (line == path.size())
        {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < path.size(); i++)
        {
            if (isValid(line, i, path))
            {
                path[line][i] = 'Q';
                trackback(line + 1, path);
                path[line][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        string row(n, '.');
        vector<string> path(n, row);
        trackback(0, path);
        return result;
    }
};