//
// Created by 18483 on 2025/1/19.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣784.字母大小写全排列
/*
 * 本题的基本思路是根据是否需要转变大小写分情况进行递归，如果是字母就走两种递归，一种是大写，另外一种是小写，否则就是数字直接走即可
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

        // 遇到字母时走两种
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
