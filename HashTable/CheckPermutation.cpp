//
// Created by 18483 on 2025/1/15.
//
#include <iostream>
#include <algorithm>
using namespace std;

// 力扣面试题01.02.判定是否互为字符重排
// 自己动手
class Solution0102
{
public:
    bool CheckPermutation(string s1, string s2)
    {
        // 长度不等一定不是重排
        if (s1.size() != s2.size())
            return false;

        int hash[26] = {0};
        // for (auto& ch : s2)
        //     hash[ch - 'a']++;
        for_each(s2.begin(), s2.end(), [&](char ch)
        {
            hash[ch - 'a']++;
        });

        for (auto &ch: s1)
            if (--hash[ch - 'a'] < 0)
                return false;


        return true;
    }
};

// 库函数
class Solution0102_2
{
public:
    bool CheckPermutation(string s1, string s2)
    {
        if(s1.size() != s2.size())
            return false;
        return is_permutation(s1.begin(), s1.end(), s2.begin());
    }
};