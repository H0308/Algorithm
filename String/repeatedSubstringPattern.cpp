//
// Created by 18483 on 2024/11/21.
//
#include <iostream>
#include <vector>
using namespace std;

// ����459.�ظ������ַ���
// �ⷨ1�������ⷨ


// �ⷨ2���ƶ�ƥ��
class Solution459_2
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // ��ԭ�ַ�����������ƴ��
        string base = s + s;

        // ƴ�Ӻ���ַ���ȥ����β�ַ������ԭ�ַ���
        // �ҵ�����true�����򷵻�false
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

// �ⷨ3��KMP
class Solution459_3
{
public:
    void getNext(vector<int> &next, const string &s)
    {
        // ��ʼ����ر���
        int prefix = 0;
        for (int suffix = 1; suffix < s.size(); suffix++)
        {
            // ǰ��׺����ͬ���
            while (prefix - 1 >= 0 && s[prefix] != s[suffix])
            {
                prefix = next[prefix - 1];
            }

            // ǰ��׺��ͬ���
            if (s[prefix] == s[suffix])
                prefix++;

            // ����next����
            next[suffix] = prefix;
        }
    }

    bool repeatedSubstringPattern(string s)
    {
        if (s.size() <= 1)
        {
            return false;
        }
        // ����next���鲢���nextֵ
        vector<int> next(s.size());
        getNext(next, s);

        int len = s.size();
        int lps = next[len - 1];

        // ��� next �������һ��ֵ��Ϊ0�������ַ��������� (len - lps) �ı�������˵���������ظ��Ӵ�����
        // �ж�lps��Ϊ0��Ϊ��ȷ���ַ����п������ظ����Ӵ�����
        return lps > 0 && len % (len - lps) == 0;
    }
};
