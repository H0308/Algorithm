//
// Created by 18483 on 2025/1/21.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣1219.黄金矿工
/*
 * 本题的基本思路就是固定每一个有效的起点，从该起点出发获取每一条有效路径上的总和，直到求出最大值
 * 因为不能重复走一个位置，所以需要used数组去重
 */
class Solution1219
{
public:
    int maxVal = INT_MIN;

    int _getMaximumGold(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &used)
    {
        // 越界或者当前位置为0
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || used[row][col] || grid[row][col] == 0)
            return 0;

        used[row][col] = true;

        // 上
        int top = _getMaximumGold(grid, row - 1, col, used);
        // 下
        int bottom = _getMaximumGold(grid, row + 1, col, used);
        // 左
        int left = _getMaximumGold(grid, row, col - 1, used);
        // 右
        int right = _getMaximumGold(grid, row, col + 1, used);

        // 找到最大的叶子
        int ret = max(max(top, bottom), max(left, right));

        used[row][col] = false;

        return ret + grid[row][col];
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        vector<vector<bool>> used(grid.size(), vector<bool>(grid[0].size(), false));

        // 枚举每一个位置
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                maxVal = max(maxVal, _getMaximumGold(grid, i, j, used));

        return maxVal;
    }
};