//
// Created by 18483 on 2025/1/20.
//
#include <iostream>
#include <vector>

using namespace std;

// ����526.����������
/*
 * ����Ļ���˼·���Ǹ����������еĹ���ö�����п��ܵ������������Ҫע�⣬���ݸ�������n����һ��λ����n��������ڶ���λ����n-1��������Դ�����
 * ���Դ�ʱ����Ҫ�漰����֦ȥ�أ���ֹ��ͬһ���������н���г���һ������ʹ�����ε����
 * ���⣬��һ����ֵ�޷������������е�����������Ҫö�ٺ����ֵ������ֱ������ѭ��
 */
class Solution526
{
public:
    int count = 0;

    void backtracking(int n, int index, vector<bool> &used)
    {
        // index����nʱ˵���Ѿ�����Ҷ�ӽڵ�
        if (index > n)
        {
            count++;
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            // �жϵ�ǰֵ�Ƿ��������������������֮һ
            // ����Ϳ��Լ������еݹ飬����ǰ����ֱ���ų�
            if (i % index == 0 || index % i == 0)
            {
                if (used[i])
                    continue;

                used[i] = true;
                backtracking(n, index + 1, used);
                used[i] = false;
            }
            else
                continue; // ��ǰֵ�������������У�����ö�ٺ����ֵ
        }
    }

    int countArrangement(int n)
    {
        vector<bool> used(n + 1, false);
        backtracking(n, 1, used);

        return count;
    }
};
