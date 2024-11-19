//
// Created by 18483 on 2024/11/19.
//
#include <iostream>
#include <vector>
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
class Solution28_2
{
public:
    void getNext(vector<int> &next, string &needle)
    {
        // 初始化相关变量
        int prefixEnd = 0;
        // 遍历
        // 后缀从1开始，形成比较
        for (int suffixEnd = 1; suffixEnd < needle.size(); suffixEnd++)
        {
            // 如果后缀字符和前缀字符不相等，说明遇到了不相等的子串
            // 此时prefixEnd就要向前移动找重新相同的位置
            // 如果字符串找到开始都没有找到说明此时没有最长相等前后缀
            while (prefixEnd - 1 >= 0 && needle[prefixEnd] != needle[suffixEnd])
            {
                // prefixEnd回到上一次的具有相等前后缀的位置
                prefixEnd = next[prefixEnd - 1];
            }

            // 如果二者相等，说明此时新增了最长相等前后缀
            // 更改最长相等前后缀的长度
            if (needle[prefixEnd] == needle[suffixEnd])
            {
                prefixEnd++;
            }

            // 更新当前next数组
            next[suffixEnd] = prefixEnd;
        }
    }

    int strStr(string haystack, string needle)
    {
        // 构建next数组
        vector<int> next(needle.size());
        // 填充next值
        getNext(next, needle);

        int j = 0;
        // 遍历文本串
        for (int i = 0; i < haystack.size(); i++)
        {
            // 如果出现不同，说明此时要找到最长相等前后缀的长度
            // 回退到长度对应的位置值重新比较
            while (j - 1 >= 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }

            // 如果相同，说明需要继续匹配
            if (haystack[i] == needle[j])
                j++;

            // 如果j此时走到了模式串的结尾，则i一定在下一个待匹配字符的位置
            // 此时要求的匹配的子串的起始位置，与当前的i构成的区间就是左闭右闭
            // 所以返回i - needle.size() + 1
            if (j == needle.size())
                return i - needle.size() + 1;
        }

        // 找不到返回-1
        return -1;
    }
};
