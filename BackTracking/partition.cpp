//
// Created by 18483 on 2025/1/10.
//
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

// 力扣131.分割回文串
/*
 * 对于分割问题，首先要思考为什么不可以直接用迭代法解决
 * 分割的本质实际上就是取出所有的结果依次判断，此时就会涉及到每一个字符都可能是下一个子串的起点，如果使用循环，在找到一处不符合要求的子串时
 * 还需要考虑如何回归到上一个起点，整体代码的复杂程度就会很高，所以对于分割问题也需要考虑使用回溯解决
 *
 * 接下来考虑如何分割，有了上面的分析，可以知道分割的本质，利用该性质可以考虑思路：固定一个起点和终点，判断中间的子字符串是否是回文串即可
 * 因为每一次分割都需要考虑从最开始的字符开始，所以分割的起点就是第一个字符，接着依次确定终点即可
 */
class Solution131_1
{
public:
    vector<vector<string>> ret;
    vector<string> temp;
    // 判断是否是回文串
    bool isPalindrome(const string &s)
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

    void backtracking(const string &s, int start)
    {
        if (start == s.size())
        {
            ret.push_back(temp);
            return;
        }

        for (int i = start; i < s.size(); i++)
        {
            string path = s.substr(start, i - start + 1);
            if (isPalindrome(path))
                temp.push_back(path);
            else
                continue;
            backtracking(s, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);

        return ret;
    }
};

class Solution131_2
{
public:
    vector<vector<string>> ret;
    vector<string> path;

    vector<vector<string>> partition(string s)
    {
        function<bool(const string &)> isPalindrome =
                [&](const string &s) -> bool
        {
            for (int left = 0, right = s.size() - 1; left <= right;)
            {
                while (left <= s.size() - 1 && !isalnum(s[left]))
                    left++;
                while (right >= 0 && !isalnum(s[right]))
                    right--;

                if (left <= s.size() - 1 && right >= 0 &&
                    tolower(s[left]) != tolower(s[right]))
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
        };
        function<void(const string &, int)> backtracking =
                [&](const string &s, int start) -> void
        {
            if (start == s.size())
            {
                ret.push_back(path);
                return;
            }

            for (int i = start; i < s.size(); i++)
            {
                string str = s.substr(start, i - start + 1);
                if (isPalindrome(str))
                    path.push_back(str);
                else
                    continue;

                backtracking(s, i + 1);
                path.pop_back();
            }
        };

        backtracking(s, 0);

        return ret;
    }
};
