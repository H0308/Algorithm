//
// Created by 18483 on 2025/1/3.
//
#include <iostream>
using namespace std;

// 力扣50.Pow(x, n)
// 暴力递归
class Solution50_1_1
{
public:
    double myPow(double x, int n)
    {
        if (n == 1)
            return x;
        double ret = 0;
        if (n < 0)
            ret = myPow(1 / x, n - 1);
        else
            ret = myPow(x, n - 1);

        return ret * x;
    }
};

// 暴力循环
class Solution_1_2
{
public:
    double myPow(double x, int n)
    {
        double base = x;
        if (n == 0)
            return 1.0;
        for (int i = 1; i < abs(n); i++)
            x = base * x;

        if (n < 0)
            x = 1 / x;

        return x;
    }
};

// 快速幂
// 折半思想
class Solution50_2
{
public:
    double myPow(double x, int n)
    {
        if (!n)
            return 1;

        // 处理负数情况：转换为分数进行幂运算
        if (n < 0)
            x = 1 / x;

        // 强转为long long防止-2^31溢出
        double ret = myPow(x, abs((long long) n) / 2);
        // n为奇数时多乘一次x
        return n % 2 == 0 ? ret * ret : ret * ret * x;
    }
};