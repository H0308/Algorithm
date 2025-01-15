//
// Created by 18483 on 2025/1/15.
//
#include <iostream>
#include <algorithm>
using namespace std;

// 力扣面试题01.04.回文排列
class Solution0104
{
public:
    bool canPermutePalindrome(string s)
    {
        // 统计字符串中字符的个数
        int hash[128] = {0};
        // 判断是否满足出现奇数次的字符只出现1次或者0次
        int count = 0;
        // for (auto& ch : s) {
        //     hash[ch]++;
        //     if (hash[ch] % 2 == 0)
        //         count--;
        //     else
        //         count++;
        // }
        for_each(s.begin(), s.end(), [&](char ch)
        {
            hash[ch]++;
            if (hash[ch] % 2 == 0)
                count--;
            else
                count++;
        });

        return count <= 1;
    }
};
