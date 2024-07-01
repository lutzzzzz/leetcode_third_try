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
    bool isValid(char num, int row, int col, vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (board[row][i] == num)
                return false;
        }
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[j][col] == num)
                return false;
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++)
        {
            for (int j = startCol; j < startCol + 3; j++)
            {
                if (board[i][j] == num)
                    return false;
            }
        }
        return true;
    }
    bool trackback(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                    continue;
                for (char num = '1'; num <= '9'; num++)
                {
                    if (isValid(num, i, j, board))
                    {
                        board[i][j] = num;
                        if (trackback(board))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        trackback(board);
    }
};