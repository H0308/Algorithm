//
// Created by 18483 on 2025/1/19.
//
#include <iostream>
#include <vector>

using namespace std;

// ����784.��ĸ��Сдȫ����
/*
 * ����Ļ���˼·�Ǹ����Ƿ���Ҫת���Сд��������еݹ飬�������ĸ�������ֵݹ飬һ���Ǵ�д������һ����Сд�������������ֱ���߼���
 */
class Solution784
{
public:
    vector<string> ret;

    void backtracking(const string &s, int start, string path)
    {
        if (start == s.size())
        {
            ret.push_back(path);
            return;
        }

        // ������ĸʱ������
        if (isalpha(s[start]))
        {
            backtracking(s, start + 1, path + (char) toupper(s[start]));
            backtracking(s, start + 1, path + (char) tolower(s[start]));
        }
        else
            backtracking(s, start + 1, path + s[start]);
    }

    vector<string> letterCasePermutation(string s)
    {
        backtracking(s, 0, "");

        return ret;
    }
};
