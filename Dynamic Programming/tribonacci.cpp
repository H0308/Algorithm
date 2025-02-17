//
// Created by 18483 on 2025/2/17.
//
#include <iostream>
#include <vector>

using namespace std;

// ����1137.��N��̩��������
/*
 * �����岽����쳲�������һ��
 */
class Solution1137_1
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

        return dp[n];
    }
};

// �ռ��Ż���ͬ��ʹ�ù��������Ż�
class Solution1137_2
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        int cur = 0;
        int prev = 1;
        int prevP = 1;
        int prevPP = 0;

        for (int i = 3; i <= n; i++)
        {
            cur = prev + prevP + prevPP;
            prevPP = prevP;
            prevP = prev;
            prev = cur;
        }

        return cur;
    }
};
