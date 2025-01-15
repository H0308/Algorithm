//
// Created by 18483 on 2025/1/15.
//
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// ����51.N�ʺ�
/*
 * ������Ҫ���Ѷ����ڴ����ά����Ļ��ݣ�ͨ����ͼ����+���ݹ���ģ�⼴�ɽ������
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
            // ��Ϊÿһ�εݹ�ֻ���ڵ�ǰ�����һ��Ԫ�أ�����ͬһ�п��Բ�ͬ�ж�

            // �����
            for (int i = 0; i < row; i++)
                if (path[i][col] == 'Q')
                    return false;

            // ��� 45�Ƚ��Ƿ��лʺ�
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
                if (path[i][j] == 'Q')
                    return false;

            // ��� 135�Ƚ��Ƿ��лʺ�
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
                if (path[i][j] == 'Q')
                    return false;

            return true;
        };

        function < void(int) > backtracking = [&](int row)
        {
            // ���������ڸ�����ʱ˵���յ����
            if (row == n)
            {
                ret.push_back(path);
                return;
            }

            // ����ÿһ�У�����ж�ָ��λ�ÿ��Է��ûʺ�ͼ���
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
