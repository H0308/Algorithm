//
// Created by 18483 on 2024/12/5.
//
#include <iostream>
#include <stack>

using namespace std;

// ����20.��Ч������
// ������ʹ�ù�ϣ��
// ��ν��Ч��������ָ��������ָ�����ŵ�˳��������������ָ�����ų��ֵ�˳��պ�ƥ��
// ���磬��������Ϊ"(["����ô��ʱ�����ŵ�˳��Ӧ�þ���"])"��������")]"
// �������Ϊ�����ŷ�ת���������Ÿ�����ͬ�Ҹպ��ǻ��Ĵ���������Ч����
    // �����������⣬��ʱ��ϣ��Ͳ�����ʹ�ã���Ϊ��ϣ����Ҫ���жϸ����Ƿ���ڣ����ǲ��ῼ�ǳ���˳��
// ��ϣ��ⷨ��������
class Solution20_1
{
public:
    bool isValid(string s)
    {
        int hash[128] = {0};

        // ��������������ӵ���ϣ��
        for (int i = 0; i < s.size(); i++)
            hash[s[i]]++;

        // �ж��������Ƿ�������ŵĸ���ƥ��
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

// ջ
class Solution
{
public:
    bool isValid(string s)
    {
        // �������������ſ϶���ƥ��
        if (s.size() % 2 != 0)
            return false;
        // �����Ž�ջ�������ų�ջƥ��
        // ������жϹ�����ջΪ�գ��������Ų�ƥ�䶼��������Ч����
        // ��ʱջΪ��˵����ʱ�����Ŷ���
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

        // �жϽ�����ջ��Ϊ�գ�˵��ջ�ڻ���������
        // �������������Ÿ�����ƥ�䣬��������Ч����
        if (!st.empty())
            return false;

        return true;
    }
};