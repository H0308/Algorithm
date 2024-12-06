//
// Created by 18483 on 2024/12/6.
//
#include <iostream>
#include <stack>

using namespace std;

// ����1047.ɾ���ַ����е����������ظ���
// ֱ��ʹ��ջ�ṹ
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

        // ������ǰջȡ�����е�Ԫ��
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

// string������Ϊջ
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
