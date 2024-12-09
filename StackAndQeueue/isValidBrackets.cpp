//
// Created by 18483 on 2024/12/5.
//
#include <iostream>
#include <stack>

using namespace std;

// 力扣20.有效的括号
// 不可以使用哈希表
// 所谓有效的括号是指左括号中指定括号的顺序必须和右括号中指定括号出现的顺序刚好匹配
// 例如，左括号先为"(["，那么此时右括号的顺序应该就是"])"，而不是")]"
// 可以理解为右括号翻转后与左括号个数相同且刚好是回文串就属于有效括号
    // 根据上面的理解，此时哈希表就不可以使用，因为哈希表主要是判断个数是否存在，但是不会考虑出现顺序
// 哈希表解法——错误
class Solution20_1
{
public:
    bool isValid(string s)
    {
        int hash[128] = {0};

        // 将所有左括号添加到哈希表
        for (int i = 0; i < s.size(); i++)
            hash[s[i]]++;

        // 判断左括号是否和右括号的个数匹配
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                hash[')']--;
            else if (s[i] == '[')
                hash[']']--;
            else if (s[i] == '{')
                hash['}']--;
        }

        if (!hash[')'] && !hash[']'] && !hash['}'])
            return true;

        return false;
    }
};

// 栈
class Solution
{
public:
    bool isValid(string s)
    {
        // 奇数个数的括号肯定不匹配
        if (s.size() % 2 != 0)
            return false;
        // 左括号进栈，右括号出栈匹配
        // 如果在判断过程中栈为空，或者括号不匹配都不属于有效括号
        // 此时栈为空说明此时左括号多了
        stack<char> st;

        for (char i : s)
        {
            if (i == '(' || i == '[' || i == '{')
                st.push(i);
            else if (i == ')')
            {
                if (st.empty() ||st.top() != '(')
                    return false;
                st.pop();
            }
            else if (i == ']')
            {
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
            }
            else if (i == '}')
            {
                if (st.empty() ||st.top() != '{')
                    return false;
                st.pop();
            }
        }

        // 判断结果如果栈不为空，说明栈内还有左括号
        // 右括号与左括号个数不匹配，不属于有效括号
        if (!st.empty())
            return false;

        return true;
    }
};