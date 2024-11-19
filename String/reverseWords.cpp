//
// Created by 18483 on 2024/11/19.
//
#include <iostream>
using namespace std;

// 力扣151. 反转字符串中的单词
// 解法1：暴力：取出原字符串中所有的单词并在尾部添加一个空格，最后去除多余的空格
class Solution151_1
{
public:
    string trim(string &s)
    {
        int index = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                index = i;
                break;
            }
        }

        int length = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                length = i;
                break;
            }
        }

        return s.substr(index, length - index + 1);
    }

    string trimInner(string &s)
    {
        string result;
        bool space = false;
        for (char c: s)
        {
            if (c != ' ')
            {
                result += c;
                space = false;
            }
            else if (!space)
            {
                result += c;
                space = true;
            }
        }
        return result;
    }

    string reverseWords(string s)
    {
        // 去除前导和尾部空格
        string copy = trim(s);

        string word;

        int wordStart = 0;

        for (int i = 0; i < copy.size(); i++)
        {
            if (i + 1 < copy.size() && copy[i] != ' ' && copy[i + 1] == ' ')
            {
                word.insert(0, copy.substr(wordStart, i - wordStart + 1) + ' ');
            }
            else if (i + 1 < copy.size() && copy[i] == ' ' && copy[i + 1] != ' ')
            {
                wordStart = i;
            }
        }

        word.insert(0,
                    copy.substr(wordStart, copy.size() - wordStart + 1) + ' ');

        string ret = trim(word);

        // 去除中间空格
        ret = trimInner(ret);

        return ret;
    }
};

// 解法2：整体反转+单词单个反转+优化移除空格逻辑
class Solution151_2
{
public:
    // 移除字符串中的空格
    // 数组移除元素的思路
    void removeSpaces(string &s)
    {
        int fast = 0, slow = 0;
        while (fast < s.size())
        {
            if (s[fast] != ' ')
            {
                // 遇到非空格就处理，即删除所有空格。
                if (slow != 0)
                    s[slow++] = ' '; // 手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (fast < s.size() && s[fast] != ' ')
                {
                    // 补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[fast++];
                }
            }

            fast++;
        }

        s.resize(slow);
    }

    // 翻转
    void reverseString(string &s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseWords(string s)
    {
        // 去除字符串中多余的空格
        removeSpaces(s);
        // 整体反转
        reverseString(s, 0, s.size() - 1);

        // 再对单个单词进行翻转
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                reverseString(s, start, i - 1);
                start = i + 1;
            }
        }

        // 最后翻转剩余的单词
        reverseString(s, start, s.size() - 1);

        return s;
    }
};
