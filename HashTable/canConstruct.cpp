//
// Created by 18483 on 2024/11/22.
//
#include <iostream>
using namespace std;

// 力扣383.赎金信
/*
 * 背景故事：
 * 假设你是一个绑架犯，你想要写一封赎金信(ransomNote)，
 * 但是你只能使用某些杂志(magazine)上的字符来拼凑这封信。
 * 每个字符在杂志上只能使用一次。你的任务是判断你是否能够从杂志上拿到足够的字符来组成赎金信。
 */
class Solution383
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int hash[26] = {0};
        for (auto ch: magazine)
            hash[ch - 'a']++;

        for (auto ch: ransomNote)
        {
            hash[ch - 'a']--;
            if (hash[ch - 'a'] < 0)
                return false;
        }

        return true;
    }
};
