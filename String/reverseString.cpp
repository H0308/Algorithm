//
// Created by 18483 on 2024/11/18.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����344.��ת�ַ���
// ʹ�ÿ⺯��
class Solution344_1
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};

// ˫ָ��+����
class Solution344_2
{
public:
    void reverseString(vector<char> &s)
    {
        for (int start = 0, end = s.size() - 1; start < end; start++, end--)
        {
            swap(s[start], s[end]);
        }
    }
};

// ����541.��ת�ַ���II
// ע����Ȿ������⣺
// 1. �����ַ�������2k���ڣ��ͷ�תǰk��
// 2. С��k����תʣ�����е��ַ�
// ����û�б�Ҫÿһ������ƶ�1���ַ�
// ��Ϊ�����ʱ��һֱ����i == 2k�Ž��д���
// ���Դ�����һ��2k���ֺ�ֱ����i����ƶ�2k����
// ��ʱi�ʹ�����һ���������ʼλ��
class Solution541
{
public:
    void reverseString(string &s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseStr(string s, int k)
    {
        // ע�⵱i����һ����תʱ��i��λ������һ�������ʼλ��
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            if (i + k < s.size())
            {
                reverseString(s, i, i + k - 1);
                continue;
            }
            reverseString(s, i, s.size() - 1);
        }

        return s;
    }
};
