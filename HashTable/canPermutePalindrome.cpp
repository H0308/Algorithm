//
// Created by 18483 on 2025/1/15.
//
#include <iostream>
#include <algorithm>
using namespace std;

// ����������01.04.��������
class Solution0104
{
public:
    bool canPermutePalindrome(string s)
    {
        // ͳ���ַ������ַ��ĸ���
        int hash[128] = {0};
        // �ж��Ƿ�������������ε��ַ�ֻ����1�λ���0��
        int count = 0;
        // for (auto& ch : s) {
        //     hash[ch]++;
        //     if (hash[ch] % 2 == 0)
        //         count--;
        //     else
        //         count++;
        // }
        for_each(s.begin(), s.end(), [&](char ch)
        {
            hash[ch]++;
            if (hash[ch] % 2 == 0)
                count--;
            else
                count++;
        });

        return count <= 1;
    }
};
