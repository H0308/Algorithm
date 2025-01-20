//
// Created by 18483 on 2025/1/20.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣36.有效的数独
/*
 * 暴力比较即可，是否需要用到回溯一定要根据题目判断，本题很明显固定了范围，从而可以确定嵌套两层for比较每个位置即可
 */
class Solution36
{
public:
    bool _isValidSudoku(vector<vector<char>> &board, int row, int col, char val)
    {
        // 判断行是否有重复
        for (int i = 0; i < 9; i++)
            if (i != col && board[row][i] == val)
                return false;

        // 判断列是否有重复
        for (int i = 0; i < 9; i++)
            if (i != row && board[i][col] == val)
                return false;

        // 判断一个格子中是否有重复
        int startRow = row / 3 * 3;
        int startCol = col / 3 * 3;

        for (int i = startRow; i < startRow + 3; i++)
            for (int j = startCol; j < startCol + 3; j++)
                if (i != (row % 3 + startRow) && j != (col % 3 + startCol) && board[i][j] == val)
                    return false;

        return true;
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    if (!_isValidSudoku(board, i, j, board[i][j]))
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
