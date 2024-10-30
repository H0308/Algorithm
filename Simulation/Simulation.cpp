//
// Created by 18483 on 2024/10/30.
//
#include <iostream>
#include <vector>
using namespace std;

// 力扣59.螺旋矩阵 II
class Solution59
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

// 力扣54.螺旋矩阵
class Solution54
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // 处理结果
        vector<int> ret;
        // 获取行和列
        int m = matrix.size();
        int n = matrix[0].size();
        // 定义上下左右边
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;

        while (top <= bottom && left <= right)
        {
            // 处理第一行
            for (int i = left; i <= right; i++)
            {
                ret.push_back(matrix[left][i]);
            }
            // 第一行处理完毕
            top++;

            // 处理第一列
            for (int i = top; i <= bottom; i++)
            {
                ret.push_back(matrix[i][right]);
            }
            // 第一列处理完毕
            right--;

            // 处理第二行
            // 需要判断是否还有第二行
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    ret.push_back(matrix[bottom][i]);
                }
                // 第二行处理完毕
                bottom--;
            }

            // 处理第二列
            // 需要判断是否还有第二列
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ret.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ret;
    }
};