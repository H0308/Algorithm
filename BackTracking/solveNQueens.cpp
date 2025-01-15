//
// Created by 18483 on 2025/1/15.
//
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// 力扣51.N皇后
/*
 * 本题主要的难度在于处理二维数组的回溯，通过画图分析+根据规则模拟即可解决本题
 */
class Solution51
{
public:
    vector<vector<string>> ret;
    vector<string> path;

    vector<vector<string>> solveNQueens(int n)
    {
        path = vector<string>(n, string(n, '.'));

        function < bool(int, int) > isValidQuene = [=](int row, int col)
        {
            // 因为每一次递归只会在当前行添加一个元素，所以同一行可以不同判断

            // 检查列
            for (int i = 0; i < row; i++)
                if (path[i][col] == 'Q')
                    return false;

            // 检查 45度角是否有皇后
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
                if (path[i][j] == 'Q')
                    return false;

            // 检查 135度角是否有皇后
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
                if (path[i][j] == 'Q')
                    return false;

            return true;
        };

        function < void(int) > backtracking = [&](int row)
        {
            // 当行数等于给定行时说明收到结果
            if (row == n)
            {
                ret.push_back(path);
                return;
            }

            // 遍历每一行，如果判断指定位置可以放置皇后就继续
            for (int i = 0; i < n; i++)
            {
                if (isValidQuene(row, i))
                {
                    path[row][i] = 'Q';
                    backtracking(row + 1);
                    path[row][i] = '.';
                }
            }
        };

        backtracking(0);

        return ret;
    }
};
