//
// Created by 18483 on 2025/1/21.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣980.不同路径Ⅲ
/*
 * 本题基本思路就是从起点依次走0的位置，直到找出可以遍历到所有0位置的路径更新计数器即可，需要注意，因为不能重复走一个位置，所以需要使用used数组去重
 */
class Solution980
{
public:
    int count = 0;

    // 判断所有0位置是否为true
    bool testZero(const vector<vector<int>> &grid, const vector<vector<bool>> &used)
    {
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 0 && !used[i][j])
                    return false;

        return true;
    }

    void _uniquePathsIII(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &used)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || used[row][col] || grid[row][col] == -1)
            return;

        if (grid[row][col] == 2 && testZero(grid, used))
        {
            count++;
            return;
        }

        used[row][col] = true;

        // 上下左右都走一遍
        _uniquePathsIII(grid, row - 1, col, used);
        _uniquePathsIII(grid, row + 1, col, used);
        _uniquePathsIII(grid, row, col - 1, used);
        _uniquePathsIII(grid, row, col + 1, used);

        used[row][col] = false;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        vector<vector<bool>> used(grid.size(), vector<bool>(grid[0].size(), false));

        // 找到1开始
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    _uniquePathsIII(grid, i, j, used);
                }
            }
        }

        return count;
    }
};
