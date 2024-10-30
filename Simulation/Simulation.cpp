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