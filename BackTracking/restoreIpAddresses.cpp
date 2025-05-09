//
// Created by 18483 on 2025/1/12.
//
#include <iostream>
#include <vector>
using namespace std;

// 力扣93.复原IP地址
/*
 * 本题的基本思路与分割字符串类似，只是要额外判断是否是合法的IP地址
 */
class Solution
{
private:
    vector<string> result; // 记录结果
    // startIndex: 搜索的起始位置，pointNum:添加逗点的数量
    void backtracking(string &s, int startIndex, int pointNum)
    {
        if (pointNum == 3)
        {
            // 逗点数量为3时，分隔结束
            // 判断第四段子字符串是否合法，如果合法就放进result中
            if (isValid(s, startIndex, s.size() - 1))
                result.push_back(s);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isValid(s, startIndex, i))
            {
                // 判断 [startIndex,i] 这个区间的子串是否合法
                s.insert(s.begin() + i + 1, '.'); // 在i的后面插入一个逗点
                pointNum++;
                backtracking(s, i + 2, pointNum); // 插入逗点之后下一个子串的起始位置为i+2
                pointNum--; // 回溯
                s.erase(s.begin() + i + 1); // 回溯删掉逗点
            }
            else
                break; // 不合法，直接结束本层循环
        }
    }

    // 判断字符串s在左闭右闭区间[start, end]所组成的数字是否合法
    bool isValid(const string &s, int start, int end)
    {
        if (start > end)
            return false;
        if (s[start] == '0' && start != end) // 0开头的数字不合法
            return false;
        int num = 0;
        for (int i = start; i <= end; i++)
        {
            num = num * 10 + (s[i] - '0');
            if (num > 255) // 如果大于255了不合法
                return false;
        }

        return true;
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        result.clear();
        if (s.size() < 4 || s.size() > 12)
            return result; // 算是剪枝了
        backtracking(s, 0, 0);
        return result;
    }
};
