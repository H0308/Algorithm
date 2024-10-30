//
// Created by 18483 on 2024/10/30.
//
#include <iostream>
#include <vector>
using namespace std;

// ����59.�������� II
class Solution59
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // ���ƺ����������������
        int startx = 0, starty = 0;
        // �����к���
        int row = 0, col = 0;
        // ����ƫ����
        int offset = 1;
        // ���������ֵ
        int count = 1;
        // �������
        vector<vector<int>> ret(n);
        for (size_t i = 0; i < n; i++)
        {
            ret[i].resize(n, 0);
        }

        // vector<vector<int>> ret(n, vector<int>(n, 0));

        // ������תȦ��
        int cycle = n / 2;
        while (cycle--)
        {
            // ����ҿ���ʽ����ÿ����
            // ��������һ����
            for (col = starty; col < n - offset; col++)
            {
                // �����ֵ
                ret[startx][col] = count++;
            }

            // ���������һ����
            for (row = startx; row < n - offset; row++)
            {
                // �����ֵ
                ret[row][col] = count++;
            }

            // �������ڶ�����
            for (; col > starty; col--)
            {
                // �����ֵ
                ret[row][col] = count++;
            }

            // ��������ڶ�����
            for (; row > startx; row--)
            {
                // �����ֵ
                ret[row][col] = count++;
            }

            // ����Ȧ
            startx++;
            starty++;
            offset++;
        }

        // ���nΪ����ʱ����м����ֵ
        if (n % 2)
            ret[startx][starty] = count;

        return ret;
    }
};

// ����54.��������
class Solution54
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // ������
        vector<int> ret;
        // ��ȡ�к���
        int m = matrix.size();
        int n = matrix[0].size();
        // �����������ұ�
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;

        while (top <= bottom && left <= right)
        {
            // �����һ��
            for (int i = left; i <= right; i++)
            {
                ret.push_back(matrix[left][i]);
            }
            // ��һ�д������
            top++;

            // �����һ��
            for (int i = top; i <= bottom; i++)
            {
                ret.push_back(matrix[i][right]);
            }
            // ��һ�д������
            right--;

            // ����ڶ���
            // ��Ҫ�ж��Ƿ��еڶ���
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    ret.push_back(matrix[bottom][i]);
                }
                // �ڶ��д������
                bottom--;
            }

            // ����ڶ���
            // ��Ҫ�ж��Ƿ��еڶ���
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