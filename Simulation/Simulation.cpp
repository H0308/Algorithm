//
// Created by 18483 on 2024/10/30.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // 控制横向坐标和纵向坐标
        int startx = 0, starty = 0;
        // 控制行和列
        int row = 0, col = 0;
        // 控制偏移量
        int offset = 1;
        // 控制填充数值
        int count = 1;
        // 结果矩阵
        vector<vector<int>> ret(n);
        for (size_t i = 0; i < n; i++)
        {
            ret[i].resize(n, 0);
        }

        // vector<vector<int>> ret(n, vector<int>(n, 0));

        // 控制轮转圈数
        int cycle = n / 2;
        while (cycle--)
        {
            // 左闭右开方式控制每条边
            // 处理横向第一条边
            for (col = starty; col < n - offset; col++)
            {
                // 填充数值
                ret[startx][col] = count++;
            }

            // 处理纵向第一条边
            for (row = startx; row < n - offset; row++)
            {
                // 填充数值
                ret[row][col] = count++;
            }

            // 处理横向第二条边
            for (; col > starty; col--)
            {
                // 填充数值
                ret[row][col] = count++;
            }

            // 处理纵向第二条边
            for (; row > startx; row--)
            {
                // 填充数值
                ret[row][col] = count++;
            }

            // 控制圈
            startx++;
            starty++;
            offset++;
        }

        // 如果n为奇数时填充中间的数值
        if (n % 2)
            ret[startx][starty] = count;

        return ret;
    }
};