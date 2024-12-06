//
// Created by 18483 on 2024/12/6.
//
#include <iostream>
#include <stack>

using namespace std;

// 力扣1047.删除字符串中的所有相邻重复项
// 直接使用栈结构
class Solution1047_1
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty() || st.top() != s[i])
                st.push(s[i]);
            else
                st.pop();
        }

        // 遍历当前栈取出其中的元素
        s.resize(st.size());
        int i = s.size() - 1;
        while (!st.empty())
        {
            s[i] = st.top();
            i--;
            st.pop();
        }

        return s;
    }
};

// string本身作为栈
class Solution1047_2
{
public:
    string removeDuplicates(string s)
    {
        string ret;
        for (auto ch: s)
        {
            if (ret.empty() || ret.back() != ch)
                ret.push_back(ch);
            else
                ret.pop_back();
        }

        return ret;
    }
};
