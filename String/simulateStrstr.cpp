//
// Created by 18483 on 2024/11/19.
//
#include <iostream>
using namespace std;

// 力扣28.找出字符串中第一个匹配项的下标
// 解法1：暴力解法
class Solution28_1
{
public:
    int strStr(string haystack, string needle)
    {
        int ret = -1;
        for (int i = 0; i < haystack.size(); i++)
        {
            int index = i;
            int j = 0;
            while (j < needle.size())
            {
                if (i < haystack.size() && haystack[i] == needle[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    break;
                }
            }

            if (j == needle.size())
            {
                ret = index;
                break;
            }

            i = index;
        }

        return ret;
    }
};

// 解法2：KMP算法
