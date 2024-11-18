//
// Created by 18483 on 2024/11/18.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 力扣344.反转字符串
// 使用库函数
class Solution344_1
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};

// 双指针+交换
class Solution344_2
{
public:
    void reverseString(vector<char> &s)
    {
        for (int start = 0, end = s.size() - 1; start < end; start++, end--)
        {
            swap(s[start], s[end]);
        }
    }
};

// 力扣541.反转字符串II
// 注意理解本题的题意：
// 1. 满足字符个数在2k以内，就翻转前k个
// 2. 小于k个则翻转剩余所有的字符
// 本题没有必要每一次向后移动1个字符
// 因为处理的时机一直都是i == 2k才进行处理
// 所以处理完一个2k部分后，直接让i向后移动2k即可
// 此时i就处于下一个区间的起始位置
class Solution541
{
public:
    void reverseString(string &s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseStr(string s, int k)
    {
        // 注意当i进行一次跳转时，i的位置是下一区间的起始位置
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            if (i + k < s.size())
            {
                reverseString(s, i, i + k - 1);
                continue;
            }
            reverseString(s, i, s.size() - 1);
        }

        return s;
    }
};
