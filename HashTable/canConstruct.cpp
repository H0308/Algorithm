//
// Created by 18483 on 2024/11/22.
//
#include <iostream>
using namespace std;

// ����383.�����
/*
 * �������£�
 * ��������һ����ܷ�������Ҫдһ�������(ransomNote)��
 * ������ֻ��ʹ��ĳЩ��־(magazine)�ϵ��ַ���ƴ������š�
 * ÿ���ַ�����־��ֻ��ʹ��һ�Ρ�����������ж����Ƿ��ܹ�����־���õ��㹻���ַ����������š�
 */
class Solution383
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int hash[26] = {0};
        for (auto ch: magazine)
            hash[ch - 'a']++;

        for (auto ch: ransomNote)
        {
            hash[ch - 'a']--;
            if (hash[ch - 'a'] < 0)
                return false;
        }

        return true;
    }
};
