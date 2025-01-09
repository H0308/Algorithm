//
// Created by 18483 on 2025/1/9.
//
#include <iostream>
using namespace std;

// 力扣125.验证回文串
// 解法1：逆序源字符串进行比较
class Solution125_1
{
public:
    bool isPalindrome(string s)
    {
        string s1;
        // 确保待比较的字符串只有数字和小写字母
        for (char ch: s)
            if (isalnum(ch))
                s1 += tolower(ch);

        string s2(s1.rbegin(), s1.rend());
        return s1 == s2;
    }
};

// 解法2：双指针
class Solution125_2
{
public:
    bool isPalindrome(string s)
    {
        for (int left = 0, right = s.size() - 1; left <= right;)
        {
            while (left <= s.size() - 1 && !isalnum(s[left]))
                left++;
            while (right >= 0 && !isalnum(s[right]))
                right--;

            if (left <= s.size() - 1 && right >= 0 && tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }

        return true;
    }
};
