//
// Created by 18483 on 2024/11/19.
//
#include <iostream>
using namespace std;

// ����28.�ҳ��ַ����е�һ��ƥ������±�
// �ⷨ1�������ⷨ
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

// �ⷨ2��KMP�㷨
