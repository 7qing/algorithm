#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> map(27, vector<bool>(9, false));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if ('1' <= board[i][j] && board[i][j] <= '9')
                {
                    int num = board[i][j] - '1';
                    map[i][num] = true;
                    map[9 + j][num] = true;
                    map[18 + i / 3 * 3 + j / 3][num] = true;
                }
            }
        }
        _solveSudoku(board, map, 0, 0);
    }

    bool _solveSudoku(vector<vector<char>> &board, vector<vector<bool>> &map, int row, int col)
    {
        // 找到下一个空位
        while (row < 9 && board[row][col] != '.')
        {
            col++;
            if (col == 9)
            {
                col = 0;
                row++;
            }
        }

        // 如果已经完成
        if (row == 9)
        {
            return true;
        }

        for (int num = 0; num < 9; num++)
        {
            // 检查数字 num 是否在当前行、列、九宫格中出现过
            if (!map[row][num] && !map[9 + col][num] && !map[18 + row / 3 * 3 + col / 3][num])
            {
                board[row][col] = '1' + num;
                map[row][num] = true;
                map[9 + col][num] = true;
                map[18 + row / 3 * 3 + col / 3][num] = true;

                // 递归调用，解决下一个位置
                if (_solveSudoku(board, map, row, col))
                {
                    return true;
                }

                // 回溯
                board[row][col] = '.';
                map[row][num] = false;
                map[9 + col][num] = false;
                map[18 + row / 3 * 3 + col / 3][num] = false;
            }
        }
        return false; // 如果所有数字都尝试过且无解，则返回 false
    }
};