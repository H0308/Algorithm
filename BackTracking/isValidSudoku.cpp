//
// Created by 18483 on 2025/1/20.
//
#include <iostream>
#include <vector>

using namespace std;

// ����36.��Ч������
/*
 * �����Ƚϼ��ɣ��Ƿ���Ҫ�õ�����һ��Ҫ������Ŀ�жϣ���������Թ̶��˷�Χ���Ӷ�����ȷ��Ƕ������for�Ƚ�ÿ��λ�ü���
 */
class Solution36
{
public:
    bool _isValidSudoku(vector<vector<char>> &board, int row, int col, char val)
    {
        // �ж����Ƿ����ظ�
        for (int i = 0; i < 9; i++)
            if (i != col && board[row][i] == val)
                return false;

        // �ж����Ƿ����ظ�
        for (int i = 0; i < 9; i++)
            if (i != row && board[i][col] == val)
                return false;

        // �ж�һ���������Ƿ����ظ�
        int startRow = row / 3 * 3;
        int startCol = col / 3 * 3;

        for (int i = startRow; i < startRow + 3; i++)
            for (int j = startCol; j < startCol + 3; j++)
                if (i != (row % 3 + startRow) && j != (col % 3 + startCol) && board[i][j] == val)
                    return false;

        return true;
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    if (!_isValidSudoku(board, i, j, board[i][j]))
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
