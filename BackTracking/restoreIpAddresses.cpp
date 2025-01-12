//
// Created by 18483 on 2025/1/12.
//
#include <iostream>
#include <vector>
using namespace std;

// ����93.��ԭIP��ַ
/*
 * ����Ļ���˼·��ָ��ַ������ƣ�ֻ��Ҫ�����ж��Ƿ��ǺϷ���IP��ַ
 */
class Solution
{
private:
    vector<string> result; // ��¼���
    // startIndex: ��������ʼλ�ã�pointNum:��Ӷ��������
    void backtracking(string &s, int startIndex, int pointNum)
    {
        if (pointNum == 3)
        {
            // ��������Ϊ3ʱ���ָ�����
            // �жϵ��Ķ����ַ����Ƿ�Ϸ�������Ϸ��ͷŽ�result��
            if (isValid(s, startIndex, s.size() - 1))
                result.push_back(s);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isValid(s, startIndex, i))
            {
                // �ж� [startIndex,i] ���������Ӵ��Ƿ�Ϸ�
                s.insert(s.begin() + i + 1, '.'); // ��i�ĺ������һ������
                pointNum++;
                backtracking(s, i + 2, pointNum); // ���붺��֮����һ���Ӵ�����ʼλ��Ϊi+2
                pointNum--; // ����
                s.erase(s.begin() + i + 1); // ����ɾ������
            }
            else
                break; // ���Ϸ���ֱ�ӽ�������ѭ��
        }
    }

    // �ж��ַ���s������ұ�����[start, end]����ɵ������Ƿ�Ϸ�
    bool isValid(const string &s, int start, int end)
    {
        if (start > end)
            return false;
        if (s[start] == '0' && start != end) // 0��ͷ�����ֲ��Ϸ�
            return false;
        int num = 0;
        for (int i = start; i <= end; i++)
        {
            num = num * 10 + (s[i] - '0');
            if (num > 255) // �������255�˲��Ϸ�
                return false;
        }

        return true;
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        result.clear();
        if (s.size() < 4 || s.size() > 12)
            return result; // ���Ǽ�֦��
        backtracking(s, 0, 0);
        return result;
    }
};
