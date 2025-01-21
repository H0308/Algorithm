//
// Created by 18483 on 2025/1/21.
//
#include <iostream>
#include <vector>

using namespace std;

// ����1219.�ƽ��
/*
 * ����Ļ���˼·���ǹ̶�ÿһ����Ч����㣬�Ӹ���������ȡÿһ����Ч·���ϵ��ܺͣ�ֱ��������ֵ
 * ��Ϊ�����ظ���һ��λ�ã�������Ҫused����ȥ��
 */
class Solution1219
{
public:
    int maxVal = INT_MIN;

    int _getMaximumGold(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &used)
    {
        // Խ����ߵ�ǰλ��Ϊ0
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || used[row][col] || grid[row][col] == 0)
            return 0;

        used[row][col] = true;

        // ��
        int top = _getMaximumGold(grid, row - 1, col, used);
        // ��
        int bottom = _getMaximumGold(grid, row + 1, col, used);
        // ��
        int left = _getMaximumGold(grid, row, col - 1, used);
        // ��
        int right = _getMaximumGold(grid, row, col + 1, used);

        // �ҵ�����Ҷ��
        int ret = max(max(top, bottom), max(left, right));

        used[row][col] = false;

        return ret + grid[row][col];
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        vector<vector<bool>> used(grid.size(), vector<bool>(grid[0].size(), false));

        // ö��ÿһ��λ��
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                maxVal = max(maxVal, _getMaximumGold(grid, i, j, used));

        return maxVal;
    }
};