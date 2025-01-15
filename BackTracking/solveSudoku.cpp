//
// Created by 18483 on 2025/1/15.
//
#include <iostream>
#include <vector>

using namespace std;

// ����37.������
/*
 * �������һ����ά���ݣ����ݹ���ö�������������
 */
class Solution37
{
private:
    bool backtracking(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            // ������
            for (int j = 0; j < board[0].size(); j++)
            {
                // ������
                if (board[i][j] == '.')
                {
                    for (char k = '1'; k <= '9'; k++)
                    {
                        // (i, j) ���λ�÷�k�Ƿ����
                        if (isValid(i, j, k, board))
                        {
                            board[i][j] = k; // ����k
                            if (backtracking(board))
                                return true; // ����ҵ�����һ�����̷���
                            board[i][j] = '.'; // ���ݣ�����k
                        }
                    }
                    return false; // 9�����������ˣ������У���ô�ͷ���false
                }
            }
        }
        return true; // ������û�з���false��˵���ҵ��˺�������λ����
    }

    bool isValid(int row, int col, char val, vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++) // �ж������Ƿ��ظ�
            if (board[row][i] == val)
                return false;

        for (int j = 0; j < 9; j++) // �ж������Ƿ��ظ�
            if (board[j][col] == val)
                return false;

        // ������ʼ�к��У�ע������ض�
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) // �ж�9�������Ƿ��ظ�
            for (int j = startCol; j < startCol + 3; j++)
                if (board[i][j] == val)
                    return false;

        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board);
    }
};
