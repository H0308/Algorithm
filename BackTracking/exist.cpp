//
// Created by 18483 on 2025/1/21.
//
#include <iostream>
#include <vector>

using namespace std;

// ����79.��������
/*
 * ����Ļ���˼·��ö��ÿһ��λ�ã������ǰλ������Ҫ���ַ��ͼ����ݹ������һ��������ֱ�ӷ���false
 * ��Ҫע����ǣ���Ϊֻ�е�һ���ַ���Ҫ���������ַ�������ֻ��Ҫ����������ʹ�ö�ά��������ҳ���ʼ�ַ���������ֻ��Ҫ���������ַ��Ƿ���ڽ��еݹ���Ҽ���
 */
class Solution79
{
public:
    bool _exist(vector<vector<char>> &board, int row, int col, int index, const string &word,
                vector<vector<bool>> &used)
    {
        if (index >= word.size())
            return true;

        // Խ��ֱ�ӷ���
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return false;

        // �Ѿ�ʹ�ù���λ�ò�����ʹ��
        if (used[row][col])
            return false;

        // ��ǰλ�õ��ַ�������Ŀ���ַ���ֱ�ӷ���
        if (board[row][col] != word[index])
            return false;

        // ��ǵ�ǰλ���Ѿ�ʹ��
        used[row][col] = true;

        // �ݹ����
        if (_exist(board, row - 1, col, index + 1, word, used) ||
            _exist(board, row + 1, col, index + 1, word, used) ||
            _exist(board, row, col - 1, index + 1, word, used) ||
            _exist(board, row, col + 1, index + 1, word, used))
            return true;

        used[row][col] = false;

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));

        // ö����ʼλ��
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (_exist(board, i, j, 0, word, used))
                    return true;
            }
        }

        return false;
    }
};