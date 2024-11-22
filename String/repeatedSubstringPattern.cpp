//
// Created by 18483 on 2024/11/21.
//
#include <iostream>
#include <vector>
using namespace std;

// 力扣459.重复的子字符串
// 解法1：暴力解法
class Solution459_1
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // 枚举子字符串的末尾位置
        // 子串至少重复一次，所以只有一个字符时一定结果为false
        for(int i = 1; i * 2 <= s.size(); i++)
        {
            // 子字符串重复多次，其一定是原字符串长度的倍数
            if(s.size() % i == 0)
            {
                bool flag = true;
                // 匹配当前子串是否是原字符串的基础子串
                for(int j = i; j < s.size(); j++)
                {
                    // 不需要重新枚举子串
                    if(s[j] != s[j - i])
                    {
                        flag = false;
                        break;
                    }
                }

                if(flag)
                {
                    return true;
                }
            }
        }

        // 循环走完说明原字符串并不是由某一个子串重复多次构成
        return false;
    }
};

// 解法2：双倍字符串
class Solution459_2
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // 将原字符串进行自我拼接
        string base = s + s;

        // 拼接后的字符串去掉首尾字符后查找原字符串
        // 找到返回true，否则返回false
        base.erase(0, 1);
        base.erase(base.size() - 1, 1);

        size_t pos = base.find(s);

        if (pos == string::npos)
        {
            return false;
        }
        return true;
    }
};

// 解法3：KMP
class Solution459_3
{
public:
    void getNext(vector<int> &next, const string &s)
    {
        // 初始化相关变量
        int prefix = 0;
        for (int suffix = 1; suffix < s.size(); suffix++)
        {
            // 前后缀不相同情况
            while (prefix - 1 >= 0 && s[prefix] != s[suffix])
            {
                prefix = next[prefix - 1];
            }

            // 前后缀相同情况
            if (s[prefix] == s[suffix])
                prefix++;

            // 更新next数组
            next[suffix] = prefix;
        }
    }

    bool repeatedSubstringPattern(string s)
    {
        if (s.size() <= 1)
        {
            return false;
        }
        // 创建next数组并填充next值
        vector<int> next(s.size());
        getNext(next, s);

        int len = s.size();
        int lps = next[len - 1];

        // 如果 next 数组最后一个值不为0，并且字符串长度是 (len - lps) 的倍数，则说明可以由重复子串构成
        // 判断lps不为0是为了确保字符串有可能由重复的子串构成
        return lps > 0 && len % (len - lps) == 0;
    }
};
