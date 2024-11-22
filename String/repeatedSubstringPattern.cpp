//
// Created by 18483 on 2024/11/21.
//
#include <iostream>
#include <vector>
using namespace std;

// ����459.�ظ������ַ���
// �ⷨ1�������ⷨ
class Solution459_1
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // ö�����ַ�����ĩβλ��
        // �Ӵ������ظ�һ�Σ�����ֻ��һ���ַ�ʱһ�����Ϊfalse
        for(int i = 1; i * 2 <= s.size(); i++)
        {
            // ���ַ����ظ���Σ���һ����ԭ�ַ������ȵı���
            if(s.size() % i == 0)
            {
                bool flag = true;
                // ƥ�䵱ǰ�Ӵ��Ƿ���ԭ�ַ����Ļ����Ӵ�
                for(int j = i; j < s.size(); j++)
                {
                    // ����Ҫ����ö���Ӵ�
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

        // ѭ������˵��ԭ�ַ�����������ĳһ���Ӵ��ظ���ι���
        return false;
    }
};

// �ⷨ2��˫���ַ���
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
