//
// Created by 18483 on 2025/1/21.
//
#include <iostream>
#include <vector>

using namespace std;

// ����980.��ͬ·����
/*
 * �������˼·���Ǵ����������0��λ�ã�ֱ���ҳ����Ա���������0λ�õ�·�����¼��������ɣ���Ҫע�⣬��Ϊ�����ظ���һ��λ�ã�������Ҫʹ��used����ȥ��
 */
class Solution980
{
public:
    int count = 0;

    // �ж�����0λ���Ƿ�Ϊtrue
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

        // �������Ҷ���һ��
        _uniquePathsIII(grid, row - 1, col, used);
        _uniquePathsIII(grid, row + 1, col, used);
        _uniquePathsIII(grid, row, col - 1, used);
        _uniquePathsIII(grid, row, col + 1, used);

        used[row][col] = false;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        vector<vector<bool>> used(grid.size(), vector<bool>(grid[0].size(), false));

        // �ҵ�1��ʼ
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
