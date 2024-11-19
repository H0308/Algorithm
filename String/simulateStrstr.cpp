//
// Created by 18483 on 2024/11/19.
//
#include <iostream>
#include <vector>
using namespace std;

// ����28.�ҳ��ַ����е�һ��ƥ������±�
// �ⷨ1�������ⷨ
class Solution28_1
{
public:
    int strStr(string haystack, string needle)
    {
        int ret = -1;
        for (int i = 0; i < haystack.size(); i++)
        {
            int index = i;
            int j = 0;
            while (j < needle.size())
            {
                if (i < haystack.size() && haystack[i] == needle[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    break;
                }
            }

            if (j == needle.size())
            {
                ret = index;
                break;
            }

            i = index;
        }

        return ret;
    }
};

// �ⷨ2��KMP�㷨
class Solution28_2
{
public:
    void getNext(vector<int> &next, string &needle)
    {
        // ��ʼ����ر���
        int prefixEnd = 0;
        // ����
        // ��׺��1��ʼ���γɱȽ�
        for (int suffixEnd = 1; suffixEnd < needle.size(); suffixEnd++)
        {
            // �����׺�ַ���ǰ׺�ַ�����ȣ�˵�������˲���ȵ��Ӵ�
            // ��ʱprefixEnd��Ҫ��ǰ�ƶ���������ͬ��λ��
            // ����ַ����ҵ���ʼ��û���ҵ�˵����ʱû������ǰ��׺
            while (prefixEnd - 1 >= 0 && needle[prefixEnd] != needle[suffixEnd])
            {
                // prefixEnd�ص���һ�εľ������ǰ��׺��λ��
                prefixEnd = next[prefixEnd - 1];
            }

            // ���������ȣ�˵����ʱ����������ǰ��׺
            // ��������ǰ��׺�ĳ���
            if (needle[prefixEnd] == needle[suffixEnd])
            {
                prefixEnd++;
            }

            // ���µ�ǰnext����
            next[suffixEnd] = prefixEnd;
        }
    }

    int strStr(string haystack, string needle)
    {
        // ����next����
        vector<int> next(needle.size());
        // ���nextֵ
        getNext(next, needle);

        int j = 0;
        // �����ı���
        for (int i = 0; i < haystack.size(); i++)
        {
            // ������ֲ�ͬ��˵����ʱҪ�ҵ�����ǰ��׺�ĳ���
            // ���˵����ȶ�Ӧ��λ��ֵ���±Ƚ�
            while (j - 1 >= 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }

            // �����ͬ��˵����Ҫ����ƥ��
            if (haystack[i] == needle[j])
                j++;

            // ���j��ʱ�ߵ���ģʽ���Ľ�β����iһ������һ����ƥ���ַ���λ��
            // ��ʱҪ���ƥ����Ӵ�����ʼλ�ã��뵱ǰ��i���ɵ������������ұ�
            // ���Է���i - needle.size() + 1
            if (j == needle.size())
                return i - needle.size() + 1;
        }

        // �Ҳ�������-1
        return -1;
    }
};
