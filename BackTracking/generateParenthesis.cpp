//
// Created by 18483 on 2025/1/18.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣22.括号生成
/*
 * 本题的基本思路是依次枚举当前位置可以填入的括号，因为是括号对，所以一个位置有两种情况：左括号和右括号，假设有三对括号对，那么需要填充的位置就是6个
 * 根据有效的括号对条件：
 * 1. 左括号数量等于右括号数量
 * 2. 从第一个括号字符开始，每一个子字符串都满足左括号数量大于等于右括号数量
 * 先枚举左括号，当左括号的个数小于需要的括号对数时，说明还可以添加左括号，否则枚举右括号，当右括号的个数大于等于左括号时，说明右括号不可以再插入
 * 最后，当右括号的个数等于括号对数时，说明已经找到满足要求个数的括号对
 */
class Solution22
{
public:
    // 记录左括号数量
    int left = 0;
    // 记录右括号数量
    int right = 0;
    string path;
    vector<string> ret;

    void backtracking(int all)
    {
        if (right == all)
        {
            ret.push_back(path);
            return;
        }

        // 有效的括号组合条件：
        // 1. 左括号数量等于右括号数量
        // 2. 从第一个括号字符开始，每一个子字符串都满足左括号数量大于等于右括号数量
        if (left < all) // 当左括号数量小于总数，说明此时还没有足够的括号对
        {
            path += "(";
            left++;
            backtracking(all);
            left--;
            path.pop_back();
        }

        if (right < left) // 当右括号数量小于左括号时就添加右括号，此时左括号已经到达最大数量
        {
            path += ")";
            right++;
            backtracking(all);
            right--;
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        backtracking(n);
        return ret;
    }
};
