//
// Created by 18483 on 2024/11/22.
//
#include <iostream>
using namespace std;

// 力扣242.有效的字母异位词
class Solution242
{
public:
    bool isAnagram(string s, string t)
    {
        if (t.size() < s.size())
        {
            return false;
        }

        int hashA[27] = {0};
        int hashB[27] = {0};

        for (auto ch: s)
        {
            hashA[ch - 'a']++;
        }

        for (auto ch: t)
        {
            hashB[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (hashA[i] != hashB[i])
            {
                return false;
            }
        }

        return true;
    }
};
