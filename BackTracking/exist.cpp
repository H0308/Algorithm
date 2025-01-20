//
// Created by 18483 on 2025/1/21.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣79.单词搜索
/*
 * 本题的基本思路是枚举每一个位置，如果当前位置是需要的字符就继续递归查找下一个，否则直接返回false
 * 需要注意的是，因为只有第一个字符需要考虑整个字符表，所以只需要在主函数中使用二维数组遍历找出起始字符，其他的只需要根据相邻字符是否存在进行递归查找即可
 */
class Solution79
{
public:
    bool _exist(vector<vector<char>> &board, int row, int col, int index, const string &word,
                vector<vector<bool>> &used)
    {
        if (index >= word.size())
            return true;

        // 越界直接返回
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return false;

        // 已经使用过的位置不能再使用
        if (used[row][col])
            return false;

        // 当前位置的字符不等于目标字符，直接返回
        if (board[row][col] != word[index])
            return false;

        // 标记当前位置已经使用
        used[row][col] = true;

        // 递归查找
        if (_exist(board, row - 1, col, index + 1, word, used) ||
            _exist(board, row + 1, col, index + 1, word, used) ||
            _exist(board, row, col - 1, index + 1, word, used) ||
            _exist(board, row, col + 1, index + 1, word, used))
            return true;

        used[row][col] = false;

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));

        // 枚举起始位置
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (_exist(board, i, j, 0, word, used))
                    return true;
            }
        }

        return false;
    }
};