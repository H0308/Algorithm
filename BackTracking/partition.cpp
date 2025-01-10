//
// Created by 18483 on 2025/1/10.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 力扣131.分割回文串
/*
 * 本题的基本思路就是根据分割位置切割字符串，如果切割的字符串是回文串就加入到结果集中
 * 难点就在于如何切割字符串，既然是切割字符串，就需要找到切割的起始位置和终止位置
 *
 * 切割的基本思路是：如果根据当前起始位置以及终止位置切割获取到的子字符串是回文串就插入到结果集，更新起始位置，否则更新终止位置
 * 其中起始位置可以使用组合问题中的start来代替，表示下一次遍历的开始，终止位置就是当前遍历的下标i
 * 注意，判断一个子串不是回文串后不要向上返回，还需要继续判断后面字符构成的子串是否可以构成回文串
 *
 * 需要注意，本题不推荐使用拼接的方式，因为拼接的方式还需要保证结果字符串中的字符在原字符串中是连续的
 * 并且拼接的方式需要对第二次判断一个子串是否是回文串做准备，即弹出上一次的所有字符
 */
class Solution131
{
public:
    vector<vector<string>> ret;
    vector<string> temp;
    // 判断是否是回文串
    bool isPalindrome(const string& s)
    {
        for (int left = 0, right = s.size() - 1; left <= right;)
        {
            while (left <= s.size() - 1 && !isalnum(s[left]))
                left++;
            while (right >= 0 && !isalnum(s[right]))
                right--;

            if (left <= s.size() - 1 && right >= 0 && tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }

        return true;
    }

    void backtracking(const string &s, int start)
    {
        if (start == s.size())
        {
            ret.push_back(temp);
            return;
        }

        for (int i = start; i < s.size(); i++)
        {
            string path = s.substr(start, i - start + 1);
            if (isPalindrome(path))
                temp.push_back(path);
            else
                continue;
            backtracking(s, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);

        return ret;
    }
};