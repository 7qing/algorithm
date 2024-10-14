#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> map(27, vector<bool>(9, false));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if ('1' <= board[i][j] && board[i][j] <= '9')
                {
                    if (map[i][board[i][j] - '1'] || map[9 + j][board[i][j] - '1'] || map[18 + i / 3 + 3 * (j / 3)][board[i][j] - '1'])
                        return false;
                    map[i][board[i][j] - '1'] = true;
                    map[9 + j][board[i][j] - '1'] = true;
                    map[18 + i / 3 + 3 * (j / 3)][board[i][j] - '1'] = true;
                }
            }
        }
        return true;
    }
};